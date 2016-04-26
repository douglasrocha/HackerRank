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
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) cin >> v[i];
        int max = 0;
        int curr = 0;
        int max_nc = 0;

        int count_negative = count_if(v.begin(), v.end(), [](int x) {
            return x < 0;
        });

        if (count_negative == v.size()) {
            int elem = *max_element(v.begin(), v.end());
            cout << elem << " " << elem << endl;
            continue;
        }

        for (int i = 0; i < v.size(); i++) {
            if (curr < 0) curr = 0;
            if (v[i] > 0) max_nc += v[i];
            curr += v[i];
            if (curr > max) max = curr;
        }

        cout << max << " " << max_nc << endl;
    }

    return 0;
}
