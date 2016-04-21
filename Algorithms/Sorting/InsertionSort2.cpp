#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

void printArr(int ar_size, int * ar) {
    for (int i = 0; i < ar_size; i++) {
        cout << ar[i];

        if (i < ar_size-1) {
            cout << " ";
        }
    }

    cout << endl;
}

void insertionSort(int ar_size, int *  ar) {
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
        }

        printArr(ar_size, ar);
    }
}
int main(void) {

    int _ar_size;
    cin >> _ar_size;
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        cin >> _ar[_ar_i];
    }

   insertionSort(_ar_size, _ar);

   return 0;
}
