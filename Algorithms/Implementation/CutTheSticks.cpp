#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int getMinimumStick(vector<int> * sticks_left) {
    if ((*sticks_left).size() == 0)
        return 0;

    int minimum = 99999;

    for (int i = 0; i < (*sticks_left).size(); i++)
        if ((*sticks_left)[i] < minimum && (*sticks_left)[i] > 0)
            minimum = (*sticks_left)[i];

    return minimum;
}

int countBiggerThanZero(vector<int> * sticks_left) {
    int count = 0;

    for (int i = 0; i < (*sticks_left).size(); i++)
        if ((*sticks_left)[i] > 0)
            count++;

    return count;
}

bool containsBiggerThanZero(vector<int> * sticks_left) {
    for (int i = 0; i < (*sticks_left).size(); i++)
        if ((*sticks_left)[i] > 0)
            return true;

    return false;
}

int main() {
    int n_sticks;
    vector<int> sticks_left;

    cin >> n_sticks;

    for (int i = 0; i < n_sticks; i++) {
        int current_stick;
        cin >> current_stick;
        sticks_left.push_back(current_stick);
    }

    while (containsBiggerThanZero(&sticks_left) > 0) {
        cout << countBiggerThanZero(&sticks_left) << endl;
        int min = getMinimumStick(&sticks_left);

        for (int i = 0; i < sticks_left.size(); i++)
            sticks_left[i] -= min;
    }

    return 0;
}
