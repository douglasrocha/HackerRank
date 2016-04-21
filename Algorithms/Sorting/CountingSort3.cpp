#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAXV 100

using namespace std;

int main() {
    int t;
    cin >> t;

    int* aux = new int[MAXV];
    int* sum = new int[MAXV];

    for (int i = 0; i < MAXV; i++) {
        aux[i] = 0;
        sum[i] = 0;
    }

    for (int i = 0; i < t; i++) {
        int a;
        string s;
        cin >> a >> s;
        aux[a] += 1;
    }

    sum[0] = aux[0];
    cout << sum[0];

    if (t > 1) cout << " ";

    for (int i = 1; i < MAXV; i++) {
        sum[i] = aux[i] + sum[i-1];
        cout << sum[i];

        if (i < MAXV - 1) cout << " ";
    }

    delete[] aux;
    delete[] sum;

    return 0;
}
