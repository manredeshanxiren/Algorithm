#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


void solve() {

 int n;
        LL s, x;
        cin >> n >> s >> x;

        vector<LL> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        LL sum = 0;
        int l = 0;
        multiset<LL> window;
        LL res = 0;

        for (int r = 0; r < n; ++r) {
            sum += a[r];
            window.insert(a[r]);

            while (l <= r && sum > s) {
                sum -= a[l];
                window.erase(window.find(a[l]));
                ++l;
            }

            if (sum == s && !window.empty() && *window.rbegin() == x) {
                res++;
            }
        }

        cout << res << '\n';
}

int main() {

    int t;
    cin >> t;

    while(t -- ) {
        solve();
    }

    return 0;
}