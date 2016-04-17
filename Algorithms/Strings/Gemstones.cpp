#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


int main() {
    vector<string> v;
    set<char> sc;
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        v.push_back(s);
        for (int i = 0; i < s.size(); i++)
            sc.insert(s[i]);
    }

    int count = 0;

    for (char c : sc) {
        bool isTrue = true;

        for (string auxs : v) {
            auto indexof = auxs.find(c);
            if (indexof < 0 || indexof >= auxs.size()) {
                isTrue = false;
                break;
            }
        }

        if (isTrue) count++;
    }

    cout << count;

    return 0;
}
