#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {
    int n; 
    cin >> n;

    vector<int> a(n + 2, -1);

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = n / 2 - 1; i >= 1; --i) {
        if(a[i] == a[i + 1] || a[n - i + 1] == a[n - i]) {
            swap(a[i], a[n - i + 1]);
        }
    }
    int res = 0;
    for(int i = 1; i < n; ++i) {
        res += (a[i] == a[i + 1]);
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