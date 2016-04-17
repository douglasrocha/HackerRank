#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isAnagram(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
        if (count(b.begin(), b.end(), a[i]) != count(a.begin(), a.end(), a[i]))
            return false;
    }

    return true;
}

bool isPositionValid(string s, int pos) {
    return pos >= 0 && pos < s.size();
}

int numberOfChangesToAnagram(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
        auto pos = b.find(a[i]);

        if (isPositionValid(b, pos)) {
            b[pos] = '_';
        }

        a[i] = '_';
    }

    return b.size() - count(b.begin(), b.end(), '_');
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        if (s.size() % 2 == 1) {
            cout << -1 << endl;
            continue;
        }

        string a = "";
        string b = "";

        for (int i = 0; i < s.size() / 2; i++) {
            a = a + s[i];
            b = b + s[s.size() / 2 + i];
        }

        if (isAnagram(a,b)) {
            cout << 0 << endl;
            continue;
        }

        cout << numberOfChangesToAnagram(a, b) << endl;
    }

    return 0;
}
