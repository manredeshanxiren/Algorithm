#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using ll = long long;
using namespace __gnu_pbds;

// 防刷 hash
struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now()
                                               .time_since_epoch()
                                               .count();
        return splitmix64(x + FIXED_RANDOM);
    }   
};

// 计算子段和为 s 且子段内所有元素 ≤ K 的个数
ll count_le(const vector<ll>& a, ll s, ll K) {
    gp_hash_table<ll,int,chash> cnt;
    cnt[0] = 1;           // 前缀和为 0 出现一次
    ll pref = 0, ans = 0;
    for (ll v : a) {
        if (v > K) {
            // 遇到“大于 K”的分界点，重置
            cnt.clear();
            pref = 0;
            cnt[0] = 1;
        } else {
            pref += v;
            auto it = cnt.find(pref - s);
            if (it != cnt.end()) ans += it->second;
            cnt[pref]++;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n; ll s, x;
        cin >> n >> s >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // f(x) = “和为 s 且所有元素 ≤ x”的子段数
        // 答案 = f(x) - f(x-1)
        ll res = count_le(a, s, x) - count_le(a, s, x - 1);
        cout << res << "\n";
    }
    return 0;
}
