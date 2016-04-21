#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAXV 100

using namespace std;

int main() {
    int n;
    cin >> n;
    int* v = new int[MAXV];

    for (int i = 0; i < MAXV; i++) {
        v[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        v[aux]++;
    }

    for (int i = 0; i < MAXV; i++) {
        cout << v[i];

        if (i < MAXV - 1) {
            cout << " ";
        }
    }

    return 0;
}
