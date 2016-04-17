#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool contains(string str, char c) {
    auto pos = str.find(c);
    return pos >= 0 && pos < str.size();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        bool found = false;
        string a, b;
        cin >> a >> b;

        for (int i = 0; i < a.size(); i++) {
            if (contains(b, a[i])) {
                found = true;
                break;
            }
        }

        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
