#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        v.push_back(i);
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int smallest_diff = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (abs(v[i-1] - v[i]) < smallest_diff)
            smallest_diff = abs(v[i-1] - v[i]);
    }

    for (int i = 1; i < n; i++) {
        if (abs(v[i-1] - v[i]) == smallest_diff)
            cout << v[i-1] << " " << v[i] << " ";
    }

    return 0;
}
