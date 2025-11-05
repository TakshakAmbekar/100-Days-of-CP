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
    1. Instead of seeing the infected zones extending, we can see uninfected zones shrinking.
    2. On each day, the gaps reduce by size 2
    3. On each day we can protect 1 house.
    4. So it is optimal to protect the largest gaps first. 
        a. protect the start of the gap. but the last house gets infected by the end of the day
        b. protect the last of the gap.
        This protects gap - 1 number of houses from ever getting infected.
        We spent 2 days to save gap - 1 houses

        if the gap is equal to 1 then we can protect that single house in one day.

        if gap ever falls below 0, that means the next houses cannot be saved, so we break out
    
*/

/*---------Intuition---------

*/

/*---------Claims---------

*/

/*---------Approach---------
    1. Keep a track of number of days passed and traverse each gap after sorting it in descending order
    2. Calculate the current gap by subtracting the number of days passed, then find the number of houses you can save.
*/

// Time taken to solve : 2 hrs
// Hints used : 3
//----------------------------------------------------------------------------------------------------

ll solve() {
    int n = readi(), m = readi();
    vi infected = readvi(m);

    if(infected.size() == 1) return 2;

    sort(all(infected));
    vi gaps;
    f(i, 0, m) gaps.pb((n + infected[(i + 1) % m] - infected[i]) % n - 1);
    sort(rall(gaps));

    int saved = 0;
    int days = 0;
    f(i, 0, m){
        int gap = gaps[i] - 2 * days;
        if(gap > 1){
            days += 2;
            saved += (gap - 1);
        }
        else if(gap == 1){
            days++;
            saved++;
        }
        else break;
    }
    
    return n - saved;
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