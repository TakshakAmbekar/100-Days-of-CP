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
#define dbg_1D(v) cout << #v << ": "; fe(x, v){cout << x << " ";} cout << endl;
#define dbg_map(m) cout << #m << ": " << endl; fe(x, m){cout << x.first << " " << x.second << endl;}


//----------------------------------------------------------------------------------------------------

/*---------Given Data---------

*/

/*---------Objective---------

*/

/*---------Constraints---------

*/

/*---------Observations---------
    1. To reach any step, you must have leg size greater than the highest step among the previous steps
*/

/*---------Intuition---------

*/

/*---------Claims---------

*/

/*---------Approach---------
    1. Make a prev_max array to store the maximum previous step height (including the current one)
    2. Make a prefix array to store the total height achieved at ith position
    3. Find the upper_bound in prev_max for a given leg size. This will be the first step that you cannot reach with given leg size.
        So answer for this will be the prefix at the previous index.
*/

// Time taken to solve : 
// Hints used : 
//----------------------------------------------------------------------------------------------------

vl solve() {
    int n = readi(), q = readi();
    vl a = readvl(n), questions = readvl(q);
    
    vl prefix(n + 1), prev_max(n + 1);
    prefix[0] = prev_max[0] = 0;

    f(i, 1, n + 1){
        prefix[i] = prefix[i - 1] + a[i - 1];
        prev_max[i] = max(prev_max[i - 1], a[i - 1]); 
    }

    vl ans ;

    // prev_max will be non-decreasing so we can use upper_bound on it
    fe(leg, questions){
        int id = upper_bound(all(prev_max), leg) - prev_max.begin();
        ans.pb(prefix[id - 1]);
    }



    return ans;
}

int main() {
    Takshak
    ll t = readl();
    while(t--) {
        vl ans = solve();
        print(ans);
    }
    return 0;
}