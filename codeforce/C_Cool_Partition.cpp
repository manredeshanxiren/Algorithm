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
    vector<int> freq(n + 1, 0);
    vector<int> distinct(n + 1, 0);

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        freq[a[i]] ++;

        if(freq[a[i]] == 1) distinct[i] = 1;

        distinct[i] += distinct[i - 1];
    }
    
    fill(freq.begin(), freq.end(), 0);

    int res = 0;
    int end = n;
    int total = 0;

    for(int i = n; i >= 1; --i) {
        freq[a[i]] ++;
        if(freq[a[i]] == 1) total ++;

        if(total == distinct[end]) {
            res ++;
            for(int j = i; j <= end; ++j) {
                freq[a[j]] = 0;
            }
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