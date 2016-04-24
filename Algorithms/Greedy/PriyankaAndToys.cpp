#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void uniquefy (vector<int>& v){
    int previousElement = -1;
    for (int i=0; i<v.size(); i++){
        if (v[i] != previousElement){
            previousElement = v[i];
        }
        else {
            v.erase(v.begin()+i);
            i--;
        }
    }
}

int main() {
    int N;
    int actual;
    int counter = 0;
    int j=0;
    cin >> N;

    vector<int> vet(N, 0);
    for (int i = 0; i < vet.size(); i++) cin >> vet[i];

    stable_sort(vet.begin(), vet.end());
    uniquefy(vet);

    for (int i = 0; i< vet.size();i++){
        actual = vet[i];
        counter++;

        for (j=1; j<5;j++)
            if (vet[i+j]-actual>4)
                break;

        if (j>1) i += j - 1;
    }

    cout << counter;

    return 0;
}
