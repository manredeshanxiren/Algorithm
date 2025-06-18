#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {
    string s;
    int n;
    cin >> n;
    cin >> s;

    vector<int> hash(256, 0);
    hash[s[0]] ++;
    hash[s[n - 1]] ++;
    for(int i = 1; i <= n - 2; ++i) {
        if(hash[s[i]] >= 1) {
            cout << "Yes" << endl;
            return ;
        }
        hash[s[i]] ++;
    }
    cout << "No" << endl;
}

int main() {

    int t;
    cin >> t;

    while(t -- ) {
        solve();
    }

    return 0;
}