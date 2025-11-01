#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

#define Takshak ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"

/* TYPES  */
#define ll long long
#define lll __int128
#define pi pair<int, int>
#define pl pair<long long, long long>
//vectors
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vl vector<long long>
#define vpl vector<pair<long long, long long>>
#define vvl vector<vector<long long>>
#define vs vector<string>
#define vps vector<pair<string, string>>
#define vvs vector<vector<string>>
//sets
#define si set<int>
#define sl set<long long>
#define sc set<char>
#define usi unordered_set<int>
#define usl unordered_set<long long>
#define usc unordered_set<char>
//maps
#define mii map<int, int>
#define mll map<long long, long long>
#define umii unordered_map<int, int>
#define umll unordered_map<long long, long long>


/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define fe(i,c) for(auto &i : c)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back

/* READS */
template <typename T>
T read() {
    T x;
    cin >> x;
    return x;
}

#define readi() read<int>()
#define readl() read<long long>()
#define readf() read<float>()
#define readd() read<double>()
#define readc() read<char>()
#define reads() read<string>()

#define readvi(n) ({ vector<int> v(n); for(auto &x:v) cin >> x; v; })
#define readvl(n) ({ vector<long long> v(n); for(auto &x:v) cin >> x; v; })
#define readvf(n) ({ vector<float> v(n); for(auto &x:v) cin >> x; v; })
#define readvd(n) ({ vector<double> v(n); for(auto &x:v) cin >> x; v; })
#define readvc(n) ({ vector<char> v(n); for(auto &x:v) cin >> x; v; })
#define readvs(n) ({ vector<string> v(n); for(auto &x:v) cin >> x; v; })

/* PRINTS */
template <class T>
void print(const T& x, int space = 0) {
    cout << x;
    if(space == 0) cout << " ";
    if(space == 1) cout << "\n";
}

template <class T>
void print(const vector<T>& v) {
    for(size_t i = 0; i < v.size(); i++) {
        if(i < v.size() - 1) print(v[i]);
        else print(v[i], 1);
    }
}

template <class T1, class T2>
void print(const pair<T1,T2>& p) {
    print(p.first);
    print(p.second);
    cout << "\n";
}


/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a*b/gcd(a,b); }
string to_upper(string s) { for (int i=0;i<(int)s.size();++i) if (s[i]>='a' && s[i]<='z') s[i]-='a'-'A'; return s; }
string to_lower(string s) { for (int i=0;i<(int)s.size();++i) if (s[i]>='A' && s[i]<='Z') s[i]+='a'-'A'; return s; }
bool prime(ll x) { if (x==1) return 0; for(int i = 2; i*i <= x; ++i) if (x%i==0) return 0; return 1; }
void yes() { cout << "YES" << "\n"; }
void no() { cout << "NO" << "\n"; }

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << " " << #z << " = " << z << endl;
#define dbg4(w,x,y,z) cout << #w << " = " << w << ", " << #x << " = " << x << " " << #y << " = " << y << ", " << #z << " = " << z << " " << endl;
#define dbg_1D(v) cout << #v << ": "; fe(x, v){cout << x << " ";} cout << endl;
#define dbg_map(m) cout << #m << ": " << endl; fe(x, m){cout << x.first << " " << x.second << endl;}

//----------------------------------------------------------------------------------------------------

/*---------Given Data---------
    1. n, x, y are given
    2. score of a permutation is sum of numbers with indices divisible by x - sum of numbers with indices divisible by y
*/

/*---------Objective---------
    find the maximum score for a permutation of size n
*/

/*---------Constraints---------

*/

/*---------Observations---------
    1. we want to put the higher numbers at the positions that are only divisible by x
    2. then put the smaller numbers at positions that are divisible by only y 
    3. positions that are divisible by both don't matter as they will be cancelled out anyway
    4. so that's basically finding the count of numbers divisible by x and not by y in range 1 to n, and putting 
        greater numbers there starting from n. Then calculating count of numbers divisible by y but not by x, and putting smaller numbers 
        there, starting from 1.
*/

/*---------Intuition---------

*/

/*---------Claims---------

*/

/*---------Approach---------

*/

//----------------------------------------------------------------------------------------------------

ll solve() {
    ll n = readl(), x = readl(), y = readl();
    ll min_count = n / y - n / lcm(x,y);
    ll max_count = n / x - n / lcm(x,y);

    ll positive = n * (n + 1) / 2 - (n - max_count) * (n - max_count + 1) / 2;
    ll negative = min_count * (min_count + 1) / 2;

    return positive - negative;
}

int main() {
    Takshak
    ll t = readl();
    while(t--) {
        ll ans = solve();
        print(ans, 1);
    }
    return 0;
}