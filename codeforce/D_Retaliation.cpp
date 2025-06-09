#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


template<typename T>
bool check(T a, T b) {
    return floor(a) == ceil(a) && floor(b) == ceil(b);
}


void solve() {
    int n;
    cin >> n;
    LL sum = 0;
    LL a = 0, b = 0;
    vector<long double> nums(n + 1);

    for(int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    if(n == 1) {
        cout << "YES" << endl;
        return ;
    }

    b = (2 * nums[1] - nums[2]) / (n + 1);

    a = nums[2] - nums[1] + b;

    if(a < 0 || b < 0) {
        cout << "NO" << endl;
        return;
    }

    for(int i = 1; i <= n; ++i) {
        nums[i] -= a * i;
        nums[i] -= b * (n - i + 1);
    }

    for(int i = 1; i <= n; ++i) {
        if(nums[i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }


    cout << "YES" << endl;
}

int main() {

    int t;
    cin >> t;

    while(t -- ) {
        solve();
    }

    return 0;
}