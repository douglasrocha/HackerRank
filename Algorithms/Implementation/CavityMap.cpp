#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isCavity(char ** matrix, int n, int row, int col) {
    vector<int> v;
    if (row == 0 || row == n-1) return false;
    if (col == 0 || col == n-1) return false;

    v.push_back(matrix[row - 1][col]);
    v.push_back(matrix[row][col - 1]);
    v.push_back(matrix[row][col + 1]);
    v.push_back(matrix[row + 1][col]);
    
    sort(v.begin(), v.end());

    return v.back() < matrix[row][col];
}

int main() {
    int n;
    cin >> n;

    char ** matrix = new char*[n];
    for(int i = 0; i < n; ++i) {
        matrix[i] = new char[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isCavity(matrix, n, i, j))
                cout << "X";
            else
                cout << matrix[i][j];
        }

        cout << endl;
    }

    return 0;
}
