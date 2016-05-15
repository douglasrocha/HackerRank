#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef unsigned long long int ull;

bool isKaprekar(ull number) {
    ull square = (ull)pow(number, 2);
    string str = to_string(square);
    int left = str.size() / 2;
    int right = str.size() - right;
    
    if (number == 1) return true;
    if (number < 9) return false;
    
    ull first = stoull(str.substr(0, left));
    ull second = right == 0 ? 0 : stoull(str.substr(left, right));
    
    if (right != 0 && second == 0) return false;
    
    return first + second == number;
}

int main() {
    int p, q;
    cin >> p >> q;
    
    vector<int> v;
    
    for (int i = p; i <= q; i++)
        if (isKaprekar(i))
            v.push_back(i);
        
    if (v.size() == 0) {
        cout << "INVALID RANGE";
        return 0;
    }
        
    for (auto i = 0; i < v.size(); i++) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    
    return 0;
}

