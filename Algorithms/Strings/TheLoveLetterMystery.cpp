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
        string s;
        cin >> s;

        int operations = 0;
        for (int i = 0; i < s.size() / 2; i++) {
            operations += abs(s[i] - s[s.size() - i - 1]);
        }

        cout << operations << endl;
    }

    return 0;
}
