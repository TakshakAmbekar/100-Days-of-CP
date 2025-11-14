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
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>

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
T read() { T x; cin >> x; return x; }

#define readi() read<int>()
#define readl() read<long long>()
#define reads() read<string>()

#define readvi(n) ({ vector<int> v(n); for(auto &x:v) cin >> x; v; })
#define readvl(n) ({ vector<long long> v(n); for(auto &x:v) cin >> x; v; })
#define readvs(n) ({ vector<string> v(n); for(auto &x:v) cin >> x; v; })

/* PRINTS */
template <class T>
void print(const T& x, int space = 0) { cout << x; if(space == 0) cout << " "; if(space == 1) cout << "\n"; }

template <class T>
void print(const vector<T>& v) { for(size_t i = 0; i < v.size(); i++) { if(i < v.size() - 1) print(v[i]); else print(v[i], 1); }}

template <class T1, class T2>
void print(const pair<T1,T2>& p) { print(p.first); print(p.second); cout << "\n"; }

/* UTILS */
#define MOD 1000000007
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a*b/gcd(a,b); }
bool is_prime(ll x) { if (x==1) return 0; for(int i = 2; i*i <= x; ++i) if (x%i==0) return 0; return 1; }

/* DEBUGS */
#define dbg(x) cout << #x << " = " << x << endl;
#define dbg_1D(v) cout << #v << ": "; fe(x, v){print(x);} cout << endl;
#define dbg_map(m) cout << #m << ": " << endl; fe(x, m){cout << x.first << " " << x.second << endl;}


//----------------------------------------------------------------------------------------------------

/*---------Given Data---------
    1. array 'marbles' of size 'n' in non-decreasing order
    2. Alice chooses a number 'a' and Bob chooses 'b'
    3. Scoring:
        a. Alice gets a point for each element that is closer to 'a' than 'b'
        b. Bob gets a point for each element that is closer to 'b' than 'a'
        c. In case of a tie, Alice gets the point
*/

/*---------Objective---------
    choose a 'b' such that the points for Bob are maximized
*/

/*---------Constraints---------
    1 <= n <= 3e5
    1 <= a <= 1e9
    1 <= marbles[i] <= 1e9
*/

/*---------Observations---------
    1. it is optimal to stay as close to 'a' as possible
    2. it is never optimal to keep b = a because in that case Bob will get 0 points
    3. so answer is either a + 1 or a - 1
    4. a + 1 will give us the best score if the number of elements that are smaller than 'a' is lesser than the number of elements that are greater than 'a'
    5. a - 1 will give us the best score if the number of elements that are smaller than 'a' is greater than the number of elements that are greater then 'a'
*/

/*---------Intuition---------

*/

/*---------Claims---------

*/

/*---------Approach---------

*/

// Time taken to solve : 
// Hints used : 
//----------------------------------------------------------------------------------------------------

ll solve() {
    int n = readi(), a = readi();
    vi marbles = readvi(n);
 
    // find the number of elements that are greater and smaller than 'a'
    int lesser = 0, greater = 0;
    fe(m, marbles){
        lesser += (m < a);
        greater += (m > a);
    }
    
    if(greater < lesser) return a - 1;
    else return a + 1;
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