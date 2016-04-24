#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a, b;

        for (int i = 0; i < n; i++) {
            a.push_back(0);
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            b.push_back(0);
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        bool isFalse = false;
        for (int i = 0; i < n; i++) {
            if (a[i] + b[i] < k) {
                cout << "NO" << endl;
                isFalse = true;
                break;
            }
        }

        if (!isFalse) cout << "YES" << endl;
    }
    return 0;
}
