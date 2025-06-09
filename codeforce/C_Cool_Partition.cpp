#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    unordered_map<int, int> all(n + 1);
    vector<int> distinct(n + 1, 0);

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        all[a[i]] ++;

        if(all[a[i]] == 1) distinct[i] = 1;

        distinct[i] += distinct[i - 1];
    }
    
    all.clear();

    int res = 0;
    int end = n;
    int total = 0;

    for(int i = n; i >= 1; --i) {
        all[a[i]] ++;
        if(all[a[i]] == 1) total ++;

        if(total == distinct[end]) {
            res ++;
            all.clear();
            end = i - 1;
            total = 0;
        }
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