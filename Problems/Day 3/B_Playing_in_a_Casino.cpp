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
    1. The deck contains 'n' cards and there are 'n' players
    2. Each player receives a card. 
    3. Each card has 'm' numbers written on it.
    4. There are pairwise games so, total games = n * (n - 1) / 2
    5. After each game, winner gets some amount of chips
        Let first player's cards be a1, a2, ..., am
        Let second player's cards be b1, b2, ..., bm
        Winner gets |a1 - b1| + |a2 - b2| + ... + |am - bm| amount of chips
*/

/*---------Objective---------
    Find the total amount of chips required so that the winners can be paid off
    i.e. sum of winnings of each round
*/

/*---------Constraints---------
    1 <= n * m <= 3e5
    1 <= card value <= 1e6
*/

/*---------Observations---------
    1. In the calculation of total winnings, it does not matter who wins.
    2. Only the differences of ith card over all the players are counted.
    3. So instead of counting winnings per match, we can calculate winnings for each card position.
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
    int n = readi(), m = readi();
    vector<vi> grid(n, vi(m));
    f(i, 0, n)
        grid[i] = readvi(m);
        
    vector<vi> cards_at_index(m, vi(n));
    f(i, 0, n)
        f(j, 0, m)
            cards_at_index[j][i] = grid[i][j];

    fe(list, cards_at_index)
        sort(all(list), greater<int>());
        
    ll pot = 0LL;
    
    fe(list, cards_at_index){
        ll curr = 0LL;
        ll curr_win = 0LL;
        rf(i, n - 1, 0){
            curr += (list[i] - list[i + 1]) * (n - 1 - i);
            curr_win += curr;
        }
        pot += curr_win;
    }

    return pot;

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