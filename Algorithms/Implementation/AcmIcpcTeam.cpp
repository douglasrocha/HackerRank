#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int countTopics(char * str, int m) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (str[i] == '1') count++;
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<char *> people;

    for (int i = 0; i < n; i++) {
        char * c = new char[m];

        for (int j = 0; j < m; j++) {
            cin >> c[j];
        }

        people.push_back(c);
    }

    int topics = 0;
    int teams = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            char * know = new char[m];
            strcpy(know, people[i]);

            for (int k = 0; k < m; k++) {
                if (people[j][k] == '1') know[k] = '1';
            }

            auto count = countTopics(know, m);
            if (count > topics) {
                topics = count;
                teams = 1;
            }
            else if (count == topics) {
                ++teams;
            }
        }
    }

    cout << topics << endl << teams << endl;

    return 0;
}
