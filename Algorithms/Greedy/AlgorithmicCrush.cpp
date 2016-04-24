#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main() {
    ull n, m;
    cin >> n >> m;

    vector<ull> v(n, 0);
    ull max = 0;
    ull value = 0;

    for (ull i = 0; i < m; i++) {
        ull a,b,k;
        cin >> a >> b >> k;

        v[a - 1] += k;

        if (b < n) v[b] -= k;
    }

    for (ull i = 0; i < n; i++) {
        value += v[i];
        if (value > max) max = value;
    }

    cout << max;

    return 0;
}
