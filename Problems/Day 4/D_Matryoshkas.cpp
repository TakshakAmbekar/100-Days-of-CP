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
    1. A set of Matroshkas containing 'm' dolls contain consecutive sized dolls starting from 's' till 's + m - 1'
    2. We are given a set of mixed sets
*/

/*---------Objective---------
    Find the minimum number of sets that could've been before mixing
*/

/*---------Constraints---------
    1 <= n <= 2e5
*/

/*---------Observations---------
    1. We need to minimize the number of sets so we need to take all consecutive numbers in one set
    2. What happens when there are duplicates? 
        We know that a new set has started
*/

/*---------Intuition---------
    Sort and use stacks to store different sets. In the worst case there will be 'n' stacks of single size which is allowed since n <= 2e5

    This has O(n2) complexity so it TLE'd

    But we only need to know the top of the stacks, so we can store the stack tops in a map along with the count of stacks that have
    that top...
    when a next doll for a top is found, we decrement the count of that top and increment the count of the top + 1
*/

/*---------Claims---------

*/

/*---------Approach---------

*/

// Time taken to solve : 30 mins
// Hints used : 0
//----------------------------------------------------------------------------------------------------

ll solve() {
    int n = readi();
    vi dolls = readvi(n);
    sort(all(dolls));

    unordered_map<int, int> top_count;
    fe(doll, dolls){
        if(top_count.count(doll - 1)){            
            if(top_count[doll - 1] == 1) top_count.erase(doll - 1);
            else top_count[doll - 1]--;

            top_count[doll]++;
        }
        else top_count[doll]++;
    }
    int count = 0;
    fe(p, top_count) count += p.second;

    return count;
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