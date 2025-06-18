#include <bits/stdc++.h>
using namespace std;

// 通用函数：试图用 primary 中的一个值固定一条“直线”来覆盖 S 中的所有点
// 如果 isRow==true，则 primary 存储要枚举的行索引，检查剩余点是否落在同一列
// 如果 isRow==false，则 primary 存储要枚举的列索引，检查剩余点是否落在同一行
bool tryCover(const vector<pair<int,int>>& S,
              const vector<int>& primary,
              bool isRow) {
    for (int x : primary) {
        int pick = -1;
        bool ok = true;
        for (auto &p : S) {
            int i = p.first, j = p.second;
            // 如果是行模式，则跳过固定行 i==x，检查列 j
            // 否则是列模式，跳过固定列 j==x，检查行 i
            int val = isRow ? j : i;
            int coord = isRow ? i : j;
            if (coord != x) {
                if (pick < 0) pick = val;
                else if (val != pick) { ok = false; break; }
            }
        }
        if (ok) return true;
    }
    return false;
}

bool canCoverRC(const vector<pair<int,int>>& S,
                const vector<int>& R,
                const vector<int>& C) {
    // 只需一行或一列自然可覆盖
    if (R.size() == 1 || C.size() == 1) 
        return true;
    // 选择元素更少的一侧进行尝试，提升效率
    if (R.size() <= C.size())
        return tryCover(S, R, /*isRow=*/true);
    else
        return tryCover(S, C, /*isRow=*/false);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        int M = 0;

        // 1) 读入并找全局最大值 M
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                M = max(M, a[i][j]);
            }

        // 2) 收集所有等于 M 的位置，并标记所在行/列
        vector<pair<int,int>> S;
        vector<char> hasR(n,0), hasC(m,0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == M) {
                    S.emplace_back(i, j);
                    hasR[i] = hasC[j] = 1;
                }

        vector<int> R, C;
        for (int i = 0; i < n; i++) if (hasR[i]) R.push_back(i);
        for (int j = 0; j < m; j++) if (hasC[j]) C.push_back(j);

        // 3) 用封装好的函数判断覆盖可行性
        bool coverable = canCoverRC(S, R, C);

        // 4) 输出结果
        cout << (coverable ? M - 1 : M) << "\n";
    }
    return 0;
}
