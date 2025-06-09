#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {
    int n;

    cin >> n;

    int l = 1;
    int r = n;

    vector<int> a(n + 1);

    int curl = 1;
    int curr = 2;

    while(l < r) {
        a[l++] = curl;
        curl += 2;
        a[r--] = curr;
        curr += 2;
    }

    if(n % 2 == 1) a[l] = curl;


    for(int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }

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