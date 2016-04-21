#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int insertionSort(int ar_size, int *  ar) {
    int count = 0;

    for (int i = 1; i < ar_size; i++) {
        int j = i-1;
        while (j >= 0) {
            if (ar[j+1] >= ar[j]) {
                break;
            }

            auto aux = ar[j+1];
            ar[j+1] = ar[j];
            ar[j] = aux;
            j--;
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    int* v = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << insertionSort(n, v) << endl;

    delete[] v;

    return 0;
}
