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
    1. a sequence of 1 to 1e12 
    2. numbers x = number of operations, y = value, k = index
    3. operation
        remove all numbers at positions that are multiples of 'y'
    4. the operation is performed 'x' times
*/

/*---------Objective---------
    find the number at 'k' index after all operations are performed
    or return -1 if after all operations, remaining numbers are less than 'k'
*/

/*---------Constraints---------
    1 <= x <= 1e5
    1 <= y
    k <= 1e12
*/

/*---------Observations---------
    1.  the constraints are too high, so we cannot simulate the removals
    2.  if y = 1, all numbers will be removed => return -1
    3.  numbers from 1 to y - 1 are never removed
    
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
    ll x = readl(), y = readl(), k = readl();

    ll LIMIT = (ll)1e12;  

    if (y == 1) return -1;

    // currentPosition is the position of 'k' in the new array after removals
    ll currentPosition = k;

    // make changes one operation at a time
    cf(i, 1, x){
        // find the count of numbers that are removed till the currentPosition
        ll removedBefore = (currentPosition - 1) / (y - 1);

        if(removedBefore == 0) break;

        if(currentPosition + removedBefore > LIMIT){
            currentPosition = LIMIT + 1;
            break;
        }

        // shift currenPosition to right by the count of removed numbers
        currentPosition += removedBefore;
    }

    if(currentPosition > LIMIT) return -1;

    return currentPosition;
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