#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {
    int n, s;

    cin >> n >> s;

    vector<int> x(n + 1);
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }   
    int l = x[1], r = x[n];
    int res = 0;
    if(s >= r) {
        res = r - l;
        res += s - r;
    } else if(s >= l && s <= r) {
        res += 2 * min(r - s, s - l);
        res += max(r - s, s - l);
    } else {
        res = r - l;
        res += l - s;
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