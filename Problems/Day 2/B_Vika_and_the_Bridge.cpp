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
// #define dbg(x) cout << #x << " = " << x << ", ";
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
template<typename... Args>
void _dbg(const char* names, Args&&... args) { string s = names; replace(s.begin(), s.end(), ',', ' '); stringstream ss(s); vector<string> vars; string temp; while (ss >> temp) vars.push_back(temp); int i = 0; ((cout << vars[i++] << " = " << args << (i < sizeof...(args) ? ", " : "\n")), ...);}

#define dbg_1D(v) cout << #v << ": "; fe(x, v){print(x);} cout << endl;
#define dbg_map(m) cout << #m << ": " << endl; fe(x, m){cout << x.first << " -> " << x.second << endl;}


//----------------------------------------------------------------------------------------------------

/*---------Given Data---------
    1. we have 'n' planks and 'k' different colors
    2. we can repaint one plank at most 
    3. we want to cross the bridge by stepping only on planks of one color
    4. color of ith plank is denoted by ci
*/

/*---------Objective---------
    find the minimum of maximum numbers of planks we need to step over if we can at most paint one plank
*/

/*---------Constraints---------
    1 <= k <= n <= 2e5
    1 <= c <= k
*/

/*---------Observations---------
    1. if at least n - 1 planks are of same color, answer is 0
    2. we'll have to step over at most n - 1 planks in the worst case
    3. if we decide that x is the answer, we can start on any plank of i = 1 to i = x. 
    4. then we need to check if after selecting a starting plank, whether we have its next occurrences within reach
*/

/*---------Intuition---------
    binary search on answer => I failed to implement this 
*/

/*---------Claims---------

*/

/*---------Approach---------
    1. find the occurrences of each color plank.
    2. then we consider the gaps between all the positions for some color. First gap is to reach the first plank. 
        Last gap is the gap between last plank and the bridge end. Then we also need the 2 largest gaps between 
        two consecutive planks.
    3. then we can at most reduce on of these gaps to half.
    4. The largest of the remaining gaps will be the optimal answer for that particular color.
    5. We do this for all the colors and get the lowest answer.

    Time complexity: O(n)
*/

// Time taken to solve : 1 hr
// Hints used : none
//----------------------------------------------------------------------------------------------------

ll solve() {
    int n = readi(), k = readi();
    vi c = readvi(n);

    // if all planks are of same color
    if(k == 1) return 0;

    // store the occurrences of each color planks
    unordered_map<int, vi> occ;
    f(i, 0, n)
        occ[c[i]].pb(i);

    int ans = n - 1;

    fe(pair, occ){
        vi planks = pair.second;
        // find the largest gap between -1 to first plank, then between planks, and then between last plank and n
        // we can only reduce one of these gaps and that will give us the optimal solution for that particular color
        int starting = planks.front(), ending = n - planks.back() - 1;
        int max1 = 0, max2 = 0;
        f(i, 1, planks.size()){
            int gap = planks[i] - planks[i - 1] - 1;
            if(gap > max1){
                max2 = max1;
                max1 = gap;
            }
            else if(gap > max2){
                max2 = gap;
            }
        }
        vi gaps = {max1, max2, starting, ending};
        sort(all(gaps), greater<int>());

        gaps[0] /= 2;

        sort(all(gaps), greater<int>());

        ans = min(ans, gaps[0]);
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