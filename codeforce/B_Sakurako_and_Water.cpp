#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int INF = 0x4f4f4f4f;


void solve() {

    int n;
    cin >> n;

    vector<vector<int>> vv(n, vector<int>(n, 0));
    vector<int> m(2 * n - 1, INF);

    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) {
            cin >> vv[i][j];
        }
    int i = 0, j = 0;
    //判断每一个斜线的最小值，并且加上这个最小值
    for(int k = 0; k < n; ++k) {
        for(int z = 0; i + z < n && j + z < n; ++z) {
            if(vv[i + z][j + z] < m[k]) m[k] = vv[i + z][j + z];
        }
        j++;
    }
    i = 1, j = 0;
    for(int k = n; k < 2 * n - 1; ++k) {
        for(int z = 0; i + z < n && j + z < n; ++z) {
            if(vv[i + z][j + z] < m[k]) m[k] = vv[i + z][j + z];
        }
        i++;
    }

    int res = 0;

    for(auto mm : m) {
        if(mm < 0) res += abs(mm);
    }

    cout << res << endl;
}

int main() {

    int t;
    cin >> t;

    while(t -- ) {
        solve();
    }

    return 0;
}