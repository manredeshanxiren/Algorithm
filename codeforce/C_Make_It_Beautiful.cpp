#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 1) 计算初始美丽值 S0
        ll S0 = 0;
        for (ll x : a) {
            S0 += __builtin_popcountll(x);
        }

        // 2) 统计每一位上有多少个 0
        //    我们考虑从最低位 b=0 开始，一直到 1<<b 超过原始 k 为止
        vector<ll> cnt(63, 0);
        for (ll x : a) {
            for (int b = 0; b < 63; b++) {
                if (((x >> b) & 1) == 0) {
                    cnt[b]++;
                }
            }
        }

        // 3) 贪心地、按位从低到高尝试“花费 2^b”把该位上的若干 0 变成 1
        ll gain = 0;
        for (int b = 0; b < 63; b++) {
            ll cost = (1LL << b);
            if (cost > k) break;
            // 最多能在这一位翻 cnt[b] 次 0->1，每次耗费 cost
            ll take = min(cnt[b], k / cost);
            gain += take;
            k -= take * cost;
        }

        // 4) 答案 = 初始美丽 + 贪心增益
        cout << (S0 + gain) << "\n";
    }

    return 0;
}
