#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {
    int n, x;

    cin >> n >> x;

    //查看关闭门的左右端点，和x比较
    int l = -1, r = -1;
    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if(l == -1 && a == 1) l = i;
        if(a == 1) r = i;
    }

    if(r - l < x) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main() {

    int t;
    cin >> t;

    while(t -- ) {
        solve();
    }

    return 0;
}