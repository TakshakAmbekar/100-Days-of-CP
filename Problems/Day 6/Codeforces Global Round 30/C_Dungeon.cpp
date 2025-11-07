#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        // storing the swords
        multiset<int> s;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        vector<int> b(m), c(m);
        // monster health
        for (int i = 0; i < m; i++) cin >> b[i];
        // reward sword strength
        for (int i = 0; i < m; i++) cin >> c[i];
        // reward sword, monster health, index triplets
        vector<array<int, 3>> v;
        for (int i = 0; i < m; i++) {
            v.push_back({c[i], b[i], i});
        }
        // sorting in descending order by reward sword strength, if equal then sort ascending by monster health
        sort(v.begin(), v.end(), [](auto &x, auto &y) {
            if (x[0] != y[0]) return x[0] > y[0];
            return x[1] < y[1];
        });
        int ans = 0;
        for (auto [r, life, i] : v) {
            // find the weakest sword to kill the monster
            auto it = s.lower_bound(life);
            if (it != s.end()) {
                int d = *it;
                s.erase(it);
                ans++;
                // if reward is greater than 0, then add the new sword
                if (r > 0) {
                    s.insert(max(d, r));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}