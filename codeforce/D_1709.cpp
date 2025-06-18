#include <bits/stdc++.h>
using namespace std;

struct Operation {
    int type, idx;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    vector<Operation> ops;

    // Step 1: 保证每个 a[i] < b[i]
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
            ops.push_back({3, i + 1});
        }
    }

    // Step 2: 分别对 a 和 b 冒泡排序
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                ops.push_back({1, i + 1});
                sorted = false;
            }
        }
    }

    sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (b[i] > b[i + 1]) {
                swap(b[i], b[i + 1]);
                ops.push_back({2, i + 1});
                sorted = false;
            }
        }
    }

    // 输出操作序列
    cout << ops.size() << '\n';
    for (auto &[type, idx] : ops)
        cout << type << " " << idx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
