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
    1. contrast of an array is the sum of absolute differences of pairwise consecutive elements
    2. contrast of a 1-sized array is 0
    3. given an array 'a'
*/

/*---------Objective---------
    build an array 'b' such that the following conditions are met
    1. 'b' is not empty
    2. 'b' is a subsequence of 'a'
    3. contrast of 'b' and 'a' is equal

    Determine the minimum possible size of 'b'
*/

/*---------Constraints---------
    1 <= n <= 3e5       => nlogn 
    0 <= ai <= 1e9
*/

/*---------Observations---------
    1. contrast of a monotonic subarray can be achieved by only keeping the first and the last elements of that
        subarray. 
    2. so if we count the number of points where the monotonicity changes, we will get our answer as count + 2
    3. edge case: when all elements are same, answer is 1
*/

/*---------Intuition---------

*/

/*---------Claims---------

*/

/*---------Approach---------

*/

// Time taken to solve : 43 mins
// Hints used : 2
//----------------------------------------------------------------------------------------------------

ll solve() {
    int n = readi();
    vi a = readvi(n);
    int count = 0;
    // count the number of points where the monotonicity changes
    int monotonicity;
    int pos = 0;
    while(pos < n - 1){
        if(a[pos] == a[pos + 1]) pos++;
        else{
            if(a[pos] < a[pos + 1]) monotonicity = 1;
            else monotonicity = -1;
            break;
        }
    }
    if(pos == n - 1) return 1;
    f(i, pos, n - 1){
        if(monotonicity == 1 && a[i] > a[i + 1]){
            monotonicity = -1;
            count++;
        }
        if(monotonicity == -1 && a[i] < a[i + 1]){
            monotonicity = 1;
            count++;
        }
    }

    return count + 2;
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