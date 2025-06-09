#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {
    int n;
    cin >> n;

    vector<int> a;
    vector<int> b;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    int r = 0;
    int lowr = 0;
    for(int i = 1; i < n; ++i) {
        if(a[i] == a[i + 1]) r = i;
        else if(b[i] == b[i + 1]) r = i;
    }

    for(int i = 0; i < n; ++i) {
        
    }

    //操作
    int del = 0;
    
    //检验
    int res = 0;

    for(int i = 1; i <= n - del; ++i) {
        if(a[i] == b[i]) res ++;
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