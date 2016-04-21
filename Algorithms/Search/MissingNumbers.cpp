#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m;
    vector<int> v;
    map<int, int> myMapA;
    map<int, int> myMapB;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        v.push_back(aux);

        if (myMapA.find(aux) == myMapA.end()) {
            myMapA[aux] = 0;
            myMapB[aux] = 0;
        }

        myMapA[aux]++;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int aux;
        cin >> aux;
        v.push_back(aux);

        if (myMapB.find(aux) == myMapB.end()) {
            myMapB[aux] = 0;
        }

        myMapB[aux]++;
    }

    sort(v.begin(), v.end());
    set<int> s(v.begin(), v.end());
    v.assign(s.begin(), s.end());

    for (int temp : v) {
        if (myMapA[temp] != myMapB[temp]) {
            cout << temp << " ";
        }
    }

    return 0;
}
