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
    a permutation of size 'n' is given (1 to n)
*/

/*---------Objective---------
    To find a subarray such that its ends do not contain min or max of the subarray
    If there is no such subarray, return -1
*/

/*---------Constraints---------
    1 <= n <= 2e5   => nlogn or n
*/

/*---------Observations---------
    1. if the permutation is sorted, it is impossible
    2. if the permutation only has one single monoticity changing point, it is impossible
    3. it is better to find the two consecutive inflection points and include one element on the left and one on the right, and ensure that these included elements do not
        exceed the inflection points in their respective directions
    4. we are given a permutation, so we don't have duplicates.
*/

/*---------Intuition---------
    greedy
*/

/*---------Claims---------

*/

/*---------Approach---------

*/

// Time taken to solve : 2 hrs
// Hints used : 3
//----------------------------------------------------------------------------------------------------

// pi solve() {
//     int n = readi();
//     vi a = readvi(n);

//     // find inflection points - O(n)
//     vi inflection_indices;

//     f(i, 1, n - 1)
//         if((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])) 
//             inflection_indices.pb(i);
    
//     if(inflection_indices.size() < 2) return {-1, -1};

//     // choose two consecutive inflections points, find the monotonicity between them, and check if one element from either ends can be added - O(n)
//     int start = 0;
//     while(start < inflection_indices.size() - 1){
//         int IP1 = inflection_indices[start], IP2 = inflection_indices[start + 1];
//         int order = a[IP2] - a[IP1];
//         // if the monotonicity is increasing, previous element should be smaller than next inflection point, and the next element should be greater than first inflection point
//         if(order > 0){  // increasing between inflection points
//             if(a[IP1 - 1] < a[IP2] && a[IP2 + 1] > a[IP1])
//                 return {IP1, IP2 + 2};  // 1-based indexing
//         }
//         else{   // decreasing between inflection points
//             if(a[IP1 - 1] > a[IP2] && a[IP2 + 1] < a[IP1])
//                 return {IP1, IP2 + 2};
//         }
//         start++;
//     }
//     return {-1, -1};
// }

pi solve() {
    int n = readi();
    vi a = readvi(n);
    set<int> s(all(a));

    int l = 0, r = n - 1;
    while(l < r){
        int mini = *s.begin();
        int maxi = *s.rbegin();
        if(a[l] != mini && a[l] != maxi && a[r] != mini && a[r] != maxi) return {l + 1, r + 1};
        if(a[l] == mini || a[l] == maxi){
            s.erase(a[l]);
            l++;
        }
        if(a[r] == mini || a[r] == maxi){
            s.erase(a[r]);
            r--;
        }
    }

    return {-1, -1};
}

int main() {
    Takshak
    ll t = readl();
    while(t--) {
        pi ans = solve();
        if(ans == make_pair(-1, -1)) print(-1, 1);
        else print(ans);
    }
    return 0;
}