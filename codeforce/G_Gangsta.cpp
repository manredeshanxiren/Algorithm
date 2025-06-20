#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // 1) 计算 A = 所有子串长度之和 = sum_{L=1..n} L * (n-L+1)
    //    公式化简得 A = n*(n+1)*(n+2)/6
    ll A = 1LL * n * (n + 1) * (n + 2) / 6;

    // 2) 构造前缀和 P[0..n]，映射 b_i = +1 (s_i='0') 或 -1 (s_i='1')
    vector<ll> P(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        P[i] = P[i - 1] + (s[i - 1] == '0' ? 1 : -1);
    }

    // 3) 排序前缀和，记为 Q，然后用公式算 B = sum_{i<j} |P[j]-P[i]|
    vector<ll> Q = P;
    sort(Q.begin(), Q.end());
    // m = n+1, 索引 0..n
    ll B = 0;
    for (int k = 0; k <= n; k++) {
        // 对于 Q[k]，它对所有前面 i<k 和后面 j>k 的贡献合并可化为：
        //   Q[k] * (2*k - n)
        B += Q[k] * (2LL * k - n);
    }

    // 4) 答案 = (A + B) / 2
    //    （因为 f(p) = (length + |c0-c1|)/2，合并两个部分后要除以 2）
    ll ans = (A + B) / 2;
    cout << ans << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t -- ) {
        solve();
    }

    return 0;
}