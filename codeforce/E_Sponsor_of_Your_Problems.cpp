#include <iostream>
#include <string>
#include <cstring>
#include <climits>
using namespace std;

int dp[10][2][2][10][10];  // 记忆化数组
string l_str, r_str;
int len;

int dfs(int pos, bool tightL, bool tightR, int sameL, int sameR) {
    //如果已经dfs到了最后一位，直接返回结果
    if (pos == len) return sameL + sameR;
    
    //取出当前的状态是否已经被计算过，如果计算过直接返回
    int &res = dp[pos][tightL][tightR][sameL][sameR];
    if (res != -1) return res;

    //初始化res，已经当前pos位置的上下边界
    res = INT_MAX;
    char low = tightL ? l_str[pos] : '0';
    char high = tightR ? r_str[pos] : '9';

    for (char d = low; d <= high; ++d) {
        bool nextTightL = tightL && (d == l_str[pos]);
        bool nextTightR = tightR && (d == r_str[pos]);
        int nextSameL = sameL + (d == l_str[pos]);
        int nextSameR = sameR + (d == r_str[pos]);

        res = min(res, dfs(pos + 1, nextTightL, nextTightR, nextSameL, nextSameR));
    }

    return res;
}

void solve() {
    int l, r;
    cin >> l >> r;

    l_str = to_string(l);
    r_str = to_string(r);
    len = l_str.size();

    memset(dp, -1, sizeof dp);
    cout << dfs(0, true, true, 0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
