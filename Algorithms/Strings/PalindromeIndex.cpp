#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string str) {
    return equal(str.begin(), str.begin() + str.size()/2, str.rbegin());
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        if (isPalindrome(s)) {
            cout << -1 << endl;
            continue;
        }

        int i = 0;
        while (i < s.size() / 2) {
            if (s[i] != s[s.size() - 1 - i]) break;
            i++;
        }

        string aux = s.substr(0, i) + s.substr(i+1, s.size()-1);
        if (isPalindrome(aux)) cout << i << endl;
        else cout << s.size() - 1 - i << endl;
    }
}
