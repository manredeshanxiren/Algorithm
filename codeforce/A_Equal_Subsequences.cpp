#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {
    int n, k;

    cin >> n >> k;

    if(n == k) {
        while( n -- ) cout << '1';
        cout << endl;
        return ;
    }

    for(int i = 1; i <= k; ++i) cout << '1';

    for(int i = 1; i <= n - k; ++i) cout << '0';

    cout << endl;
}

int main() {

    int t;
    cin >> t;

    while(t -- ) {
        solve();
    }

    return 0;
}