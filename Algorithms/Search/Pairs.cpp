#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

/* Head ends here */

pair<int,int> createPair(int i, int j) {
    if (j < i)
        return make_pair(j, i);

    return make_pair(i, j);
}

int pairs(vector < int > a,int k) {
    int ans = 0;
    map<int, bool> myMap;
    set<pair<int, int>> sPair;

    for (int temp : a) {
        myMap[temp] = true;
    }

    for (int temp : a) {
        if (!myMap[temp]) continue;
        int p1 = temp - k;
        int p2 = temp + k;

        if (myMap.find(p1) != myMap.end()) {
            sPair.insert(createPair(p1, temp));
        }

        if (myMap.find(p2) != myMap.end()) {
            sPair.insert(createPair(p2, temp));
        }
    }

    ans = sPair.size();

    return ans;
}

/* Tail starts here */
int main() {
    int res;

    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }

    res = pairs(_a,_k);
    cout << res;

    return 0;
}
