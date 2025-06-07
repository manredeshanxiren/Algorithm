#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {
    int n;

    cin >> n;

    int cur = 0;

    int i;

    for(i = 1; abs(cur) <= n; ++i) {
        int temp = 2 * i - 1;
        if(i % 2) cur -= temp;
        else cur += temp;

    }

    if(i % 2) {
        cout << "Kosuke" << endl;
    } else {
        cout << "Sakurako" << endl;
    }
}

int main() {

    int t; 
    cin >> t;
    while(t --) {
        solve();
    }



    return 0;
}