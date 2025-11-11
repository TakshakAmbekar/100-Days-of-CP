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
    1. two integers 'x' and 'y'
    2. an array 'a' of length 'n'
    3. a pair of indices i < j is beautiful if, 
        i. ai + aj is divisible by x and 
        ii. ai - aj is divisible by y
*/

/*---------Objective---------
    count the number of beautiful pairs in the array
*/

/*---------Constraints---------

*/

/*---------Observations---------
    1. if the remainders of two numbers is same under modulo y, condition ii is satisfied
    2. if the remainders of two numbers under modulo x add up to 0 or x, condition i is satisfiec.
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
    ll n = readl(), x = readl(), y = readl();
    vl a = readvl(n);

    // maintain the numbers for each remainder modulo y
    map<ll, vl> y_rem;

    f(i, 0, n){
        y_rem[a[i] % y].pb(a[i]);
    }

    ll ans = 0;

    fe(rem, y_rem){
        vl nums = rem.second;
        // map to store counts of reminders under modulo x
        map<ll, ll> mp1;
        // count occurrences of each remainder 
        f(i, 0, nums.size())
            mp1[nums[i] % x]++;
    
        // calculte the number of beautiful pairs
        fe(rem, mp1){
            if(rem.first == 0 || (rem.first == x / 2 && x % 2 == 0)){
                ll count = rem.second;
                ans += (count * (count - 1) / 2);
                rem.second = 0;
            }
            else{
                ll count1 = rem.second, count2 = mp1[x - rem.first];
                ans += count1 * count2;
                // avoid double-counting
                mp1[x - rem.first] = 0; 
            }
        }
    }

    return ans;
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