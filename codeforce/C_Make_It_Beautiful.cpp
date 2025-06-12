#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 1. 计算初始美丽值 S0
        ll S0 = 0;
        vector<ll> cost(n);
        for (int i = 0; i < n; i++) {
            // popcount of a[i]
            S0 += __builtin_popcountll(a[i]);
            // 第一件的花费：偶数 -> 1，奇数 -> 2
            cost[i] = (a[i] % 2 == 0 ? 1 : 2);
        }

        // 2. 排序 cost，计算前缀和
        sort(cost.begin(), cost.end());
        vector<ll> pref(n+1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + cost[i-1];
        }

        // 3. 枚举取前 j 件“首件增益”，剩余预算买“后续件”
        ll maxGain = 0;
        for (int j = 0; j <= n; j++) {
            if (pref[j] > k) break;
            ll rem = k - pref[j];
            ll extra = rem / 2;  // 每 2 次操作额外 +1 美丽
            maxGain = max(maxGain, (ll)j + extra);
        }

        // 4. 输出答案
        cout << (S0 + maxGain) << "\n";
    }

    return 0;
}
