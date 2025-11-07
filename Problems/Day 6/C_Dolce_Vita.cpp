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
    1. there are 'n' shops each selling sugar for a price of 'ai'
    2. each day prices increase by 1 in each shop
    3. you can buy only 1 pack per shop per day
    4. you have a daily budget of 'x' 
*/

/*---------Objective---------
    find the total number of packs you can buy 
*/

/*---------Constraints---------
    1 <= n <= 2e5   -> nlogn
    1 <= x <= 1e9
    1 <= ai <= 1e9
*/

/*---------Observations---------
    1. It is always optimal to start buying from the shops with lowest price, so we can sort the prices
    2. we can maintain a prefix sum of these sorted prices and find the upper_bound of 'x' to find the number of packs that can be bought 
        on that day
    3. how do we efficiently track the prefix on each day though?
        - because prefix[i] will increase by (i + 1) each day if we take zero-based indexing
        - and we want to find the upper_bound in a prefix, so we need to update the prefix array before applying the upper_bound

        ! maybe we can keep a track of the day and apply binary search on the prefix array and check if prefix[i] + day * (i + 1) is <= x
*/

/*---------Intuition---------
    sorting and prefix sum

    sorting, prefix sum and binary search
*/

/*---------Claims---------

*/

/*---------Approach---------

*/

// Time taken to solve : 
// Hints used : 
//----------------------------------------------------------------------------------------------------

ll solve() {
    ll n = readl(), x = readl();
    vl a = readvl(n);
    sort(all(a));
    vl prefix(n);
    prefix[0] = a[0];
    f(i, 1, n) prefix[i] = prefix[i - 1] + a[i];
    ll ans = 0;
    ll day = 0;
    dbg_1D(prefix);
    while(true){
        ll l = 0, r = n - 1;
        ll curr_bought = 0;
        while(l <= r){
            ll mid = l + (r - l) / 2;
            ll required = prefix[mid] + day * (mid + 1);
            dbg(mid); dbg(required);
            // if we have the budget we can try and go for more
            if(required <= x){
                // dbg(mid); dbg(curr_bought);
                l = mid + 1;
                curr_bought = max(curr_bought, l - r + 1);
            }
            // else we need to reduce the number of shops
            else{
                r = mid - 1;
            }
        }
        if(l == 0 && r == -1) break;
        ans += curr_bought;
        day++;
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