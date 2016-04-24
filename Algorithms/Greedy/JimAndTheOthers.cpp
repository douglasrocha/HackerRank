#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int,int> PP;
typedef long long LL;

int main() {
    int n;
    cin >> n;

    vector<pair<LL, LL>> v;

    for (LL i = 0; i < n; i++) {
        LL ti,di;
        cin >> ti >> di;
        v.push_back(make_pair(i, ti + di));
    }

    stable_sort(v.begin(), v.end(), [](const PP &l, const PP &r) {
        if (l.second == r.second)
            return l.first < l.first;

        return l.second < r.second;
    });

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first + 1;
        if (i < v.size() - 1) cout << " ";
    }

    return 0;
}
