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
    1. given an array of positive integers 'a' of size 'n'
    2. operation: choose a value 'k' and make all ai = ai % k
*/

/*---------Objective---------
    find a value 'k' such that after the operation, final array contains exactly 2 distinct numbers
*/

/*---------Constraints---------
    2 <= n <= 100
    1 <= ai <= 1e17
    1 <= k <= 1e18
*/

/*---------Observations---------
    1. if there are odd and even elements, we can choose k = 2
    2. if there are only odd or only even elements, we need to do something else...
    3. constraints on n are very low
    4. we can never choose k = 1
    
*/

/*---------Intuition---------

*/

/*---------Claims---------
    k = 2 does not work only when all numbers are odd or all are even. so, what if we check for powers of 2 till 1e18? 
    2^60 is the last number that we'll have to check and n <= 100 so that's at most 6000 operations. 
    If we find that for some power of 2 there are two unique mod values, we take that as our answer.

    This is basically checking the first mismatch of the bit from right. Suppose all the bits from 0 to i have matched
    and now i+1th bit is different, then if we mod the numbers with 2^(i+1) we will get two distinct values only. 
    One with 1 as MSB and other with 0 as MSB followed by i matching bits.
*/

/*---------Approach---------

*/

//----------------------------------------------------------------------------------------------------

ll solve() {
    int n = readi();
    vl a = readvl(n);
    ll power = 2;
    f(i, 0, 60){
        usl mods;
        fe(num, a){
            if(mods.size() > 2) break;
            mods.insert(num % power);
        }
        if(mods.size() == 2) return power;
        power = power << 1;
    }
    return power;
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