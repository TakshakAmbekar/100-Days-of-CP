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

*/

/*---------Objective---------

*/

/*---------Constraints---------

*/

/*---------Observations---------

*/

/*---------Intuition---------

*/

/*---------Claims---------

*/

/*---------Approach---------

*/

// Time taken to solve : 1 hr
// Hints used : 3
//----------------------------------------------------------------------------------------------------

vector<vi> solve() {
    int n = readi();
    vi a = readvi(n);

    // we cannot change the last two numbers
    if(a[n - 2] > a[n - 1]) return {{-1}};

    vector<vi> ans;

    // if the last number is positive, we can replace all the numbers till n-2 index to a[n-1] - a[n]
    if(a[n - 1] >= 0)
        f(i, 0, n - 2){
            vi op = {i + 1, n - 1, n};
            ans.pb(op);
        }
    
    else
        if(is_sorted(all(a))) return {};
        // if the last number is negative, then we cannot sort because their difference will be positive if a[n-2] < a[n-1]
        else return {{-1}};
    
    return ans;
}

int main() {
    Takshak
    ll t = readl();
    while(t--) {
        vector<vi> ans = solve();
        if(ans.size() == 0) print(0, 1);
        else if(ans[0][0] == -1) print(-1, 1);
        else{
            print(ans.size(), 1);    
            fe(op, ans) print(op);
        }
    }
    return 0;
}