#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    vector<int> list;
    for (int i=0; i < N; i++) {
        list.push_back(0);
        cin >> list[i];
    }

    sort(list.begin(), list.end());

    for (int i = 0; i <= N-K; i++) {
        if (list[i+K-1] - list[i] < unfairness) {
            unfairness = list[i+K-1] - list[i];
        }
    }

    cout << unfairness << "\n";
    return 0;
}
