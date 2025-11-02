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
T read() { T x; cin >> x; return x;}

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
#define PI 3.1415926535897932384626433832795
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a*b/gcd(a,b); }
bool is_prime(ll x) { if (x==1) return 0; for(int i = 2; i*i <= x; ++i) if (x%i==0) return 0; return 1; }

/* DEBUGS */
#define dbg(x) cout << #x << " = " << x << endl;
#define dbg_1D(v) cout << #v << ": "; fe(x, v){cout << x << " ";} cout << endl;
#define dbg_map(m) cout << #m << ": " << endl; fe(x, m){cout << x.first << " " << x.second << endl;}

//----------------------------------------------------------------------------------------------------

/*---------Given Data---------
    1. an array 'b' of size n * (n - 1) / 2 is made from the pairwise minimum elements from array 'a' of size 'n'.
*/

/*---------Objective---------
    1. guess the 'a' from given 'b'
*/

/*---------Constraints---------
    2 <= n <= 1e3
    -1e9 <= bi <= 1e9
*/

/*---------Observations---------
    1. The overall minimum element will have the highest occurrence.
    2. The overall largest element will have no occurrence if there are no duplicates of it. else it will appear one less
        times than the number of duplicates
    3. All the numbers from 'b' are going to be in 'a' as well... some might be repeated in 'b' and at most 1 element
        from 'a' will be missing in 'b'.
    4. We can sort the array 'b'. Then if each element is unique then the count of each unique element starting from the minimum
        should be n - i, where i starts from 1.
*/

/*---------Intuition---------

*/

/*---------Claims---------

*/

/*---------Approach---------

*/

//----------------------------------------------------------------------------------------------------

vi solve() {
    int n = readi();
    int size = n * (n - 1) / 2;
    vi b = readvi(size);

    sort(all(b));

    vi ans;
    int pos = 0;

    for(int length = n - 1; length > 0; length--){
        ans.pb(b[pos]);
        pos += length;
    }
    ans.pb(ans.back());;
    return ans;

}

int main() {
    Takshak
    ll t = readl();
    while(t--) {
        vi ans = solve();
        print(ans);
    }
    return 0;
}