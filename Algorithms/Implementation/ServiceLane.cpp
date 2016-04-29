#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int freeway, t;
    vector<int> lanes;

    cin >> freeway >> t;

    lanes.reserve(freeway);

    for (int i = 0; i < freeway; i++) {
        lanes.push_back(0);
        cin >> lanes[i];
    }

    while (t--) {
        int in, out;
        cin >> in >> out;

        int min = 99;
        for (int i = in; i <= out; i++) {
            if (lanes[i] < min) min = lanes[i];
        }

        cout << min << endl;
    }
}
