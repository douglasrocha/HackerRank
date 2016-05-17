#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;

    auto len_str = s.size();
    auto lenCeil = ceil(sqrt(len_str));
    auto lenFloor = round(sqrt(len_str));

    int rows = 0;
    int cols = 0;
    int min = 9999;

    for (int i = lenCeil; i >= 1; i--) {
        for (int j = lenFloor; j >= 1; j--) {
            auto area = lenCeil * lenFloor;
            if (area >= len_str && area < min) {
                rows = i;
                cols = j;
                min = area;
            }
        }
    }

    if (rows >= cols) {
        auto temp = rows;
        rows = cols;
        cols = temp;
    }

    char ** matrix = new char*[rows];
    for (int i = 0; i < rows; i++) matrix[i] = new char[cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = s[i*cols + j];
        }
    }

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (j*cols + i >= len_str) continue;
            cout << matrix[j][i];
        }
        cout << " ";
    }

    for (int i = 0; i < rows; i++)
        delete[] matrix[i];

    delete[] matrix;

    return 0;
}
