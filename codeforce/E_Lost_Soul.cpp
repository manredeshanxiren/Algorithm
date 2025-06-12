#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<bool> seen(n + 1, false);

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    if(a[n] == b[n]) {
        cout << n << endl;
        return ;
    }

    int res = 0;

    for(int i = n - 1; i >= 1; --i) {
        if(a[i] == b[i] || a[i] == a[i + 1] || b[i] == b[i + 1] || seen[a[i]] || seen[b[i]]) {
            res = i;
            break;
        }

        seen[a[i + 1]] = seen[b[i + 1]] = true;
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