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
    1. set S contains all numbers 1 to n
    2. operation: 
        choose k such that 1 <= k <= n and there exists atleast 1 multiple of k in S. 
        delete the smallest multiple of k. 
        the operation costs 'k'
    3. there is a set T is which is a subset of S, and you are given a binary string of size 'n' which has 1 at indices for which 
        the number is present in the set T.c
*/

/*---------Objective---------
    find the minimum cost required to transform S into T
*/

/*---------Constraints---------
    1 <= n <= 1e6
*/

/*---------Observations---------

*/

/*---------Intuition---------

*/

/*---------Claims---------

*/

/*---------Approach---------
    1. Keep a vector of size n + 1 for costs starting with all costs as 0
    2. Starting from 1, find its consecutive multiples that have been removed as well
    3. They will cost 1 to be removed as well
    4. For any subsequent number, 
        a. if the cost for that number i is 0 that means it needs to be removed using cost i. So 
            update its cost as cost[i] = i and also all of its subsequent consecutive multiples will cost i 
        b. if the cost for that number i is greater than 0 that means it was marked by some previous number.
            So it's cost will still be the previous number but the subsequenct consecutive multiples of i's costs
            need to be updated 
*/

// Time taken to solve : 2 hrs
// Hints used : 1
//----------------------------------------------------------------------------------------------------

ll solve() {
    int n = readi();
    string s = reads();

    vi cost(n + 1, 0);

    int zeros = 0;

    cf(i, 1, n){
        // i is the number
        // if the number was removed, update the cost of all of the multiples that are missing as well
        if(s[i - 1] == '0'){
            zeros++;
            if(cost[i] == 0) cost[i] = i;
            for(int j = 2 * i; j < n + 1; j += i){
                // if already marked, continue
                if(cost[j] != 0) continue;
                // if multiple is not deleted break
                else if(s[j - 1] == '1') break;
                // else make the cost = i
                else if (cost[j] == 0 && s[j - 1] == '0')
                    cost[j] = i;
            }
        }
    }

    if(zeros == n) return n;
    if(zeros == 0) return 0;

    ll total_cost = accumulate(all(cost), 0LL);
    return total_cost;
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