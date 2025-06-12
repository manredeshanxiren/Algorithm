#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << 0 << endl;
        return;
    }

    int count = 2 * (n - 1) - 1;

    cout << count << endl;
    int row = 0;
    int l, r;
    int i = 0;
    while(i < count) {
        l = 1, r = n - row;
        if(l < r) cout << row + 1<< " " << l << " " << r << endl, i++;
        int revl = r + 1, revr = n;
        if(revl < revr && row != 1) cout << row + 1 << " " << revl << " " << revr << endl, i++;

        row ++;
    }

}

int main() {

    int t;
    cin >> t;

    while(t -- ) {
        solve();
    }

    return 0;
}