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
    1. integer array 'a' for size 'n'
    2. operation:
        a. choose a range [l, r] such that 1 <= l <= r <= n
        b. replace each element in that range with a[l] + a[r]
    3. operation can only be performed once
*/

/*---------Objective---------
    maximize the total sum after the operation
*/

/*---------Constraints---------
    1 <= n <= 2e5
    0 <= ai <= 2n
*/

/*---------Observations---------
    1.  when we choose a range, the sum changes by some amount
    2.  the amount by which the sum changes can be found using prefix
    3.  gain(l, r) = newSum - oldSum
        where,  newSum = (r - l + 1) * (l + r) 
                oldSum = pref[r] - pref[l - 1]
    4.  we need to maximize this gain
    5.  separate gain into two parts
        gain    = (r - l + 1) * (l + r) - (pref[r] - pref[l - 1]) 
                = (r + 1) * l + (r + 1) * r - l * l + 1 - pref[r] + pref[l - 1]
                = (pref[l - 1] - l * l + 1) + (r * r + r - pref[r])
        leftContribution(l) = pref[l - 1] - l * l + 1
        rightContribution(r) = r * r + r - pref[r]
        newTotal = total + leftContribution(l) + rightContribution(r)
    6.  since left and right contributions are now independent, the problem reduces to finding the best 'r' > 'l' for each 'l'
    7.  we need to preprocess the suffix maximum of rightContribution so that we can find the best 'r' in O(1) for each 'l'
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
    int n = readi();
    vl values = readvl(n);

    // find the prefix
    vl pref(n + 1, 0);
    cf(i, 1, n)
        pref[i] = pref[i - 1] + values[i - 1];
    
    // initial total sum
    ll total = pref[n];

    // final sum after the operation
    ll best = total;      

    // build the rightContribution array
    vl rightContribution(n + 1);
    cf(r, 1, n)
        rightContribution[r] = r * r + r - pref[r];
    
    // preprocess the suffix such that at each 'i' we have the maximum rightContribution that we can get
    vl suf(n + 1, LLONG_MIN);
    suf[n] = rightContribution[n];
    rf(i, n, 1)
        suf[i] = max(suf[i + 1], rightContribution[i]);

    // for each 'l' get the best possible sum and update the best if needed
    cf(l, 1, n){
        ll leftContribution = pref[l - 1] - l * l + l;                  
        ll bestRight = suf[l];
        ll newTotal = total + leftContribution + bestRight;
        best = max(best, newTotal);
    }
    return best;
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