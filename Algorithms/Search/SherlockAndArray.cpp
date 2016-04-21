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
        int n;
        vector<int> v;
        cin >> n;

        while(n--) {
            int aux;
            cin >> aux;
            v.push_back(aux);
        }

        vector<int> sums;
        sums.push_back(v[0]);
        for (auto i = 1; i < v.size(); i++) {
            sums.push_back(v[i] + sums[i-1]);
        }

        bool success = false;
        if (sums.size() <= 1) {
            cout << "YES" << endl;
            continue;
        }

        for (auto i = 1; i < sums.size(); i++) {
            if (sums[sums.size() - 1] - sums[i] == sums[i - 1]) {
                cout << "YES" << endl;
                success = true;
                break;
            }
        }

        if (success != true) cout << "NO" << endl;
    }

    return 0;
}
