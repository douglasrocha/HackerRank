#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char rotateChar(char c, int k) {
    int count = k % 26;
    int pos;

    if (islower(c)) pos = c - 'a';
    else if (isupper(c)) pos = c - 'A';
    else return c;

    while (count--) pos++;
    return (char)((pos % 26) + (islower(c) ? 'a' : 'A'));
}

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;
    for (int i = 0; i < n; i++) cout << rotateChar(s[i], k);
    return 0;
}
