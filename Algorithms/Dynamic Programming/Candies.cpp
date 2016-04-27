#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if(n==1){
        cout << 1;
        return 0;
    }
    vector<int> v(n,0);
    vector<int> k(n,1);

    for(int i=0; i<n; i++) cin >> v[i];

    for(int i=0; i<n; i++){
        bool changed = false;

        for(int j=1; j<n-1; j++){
            if(v[j]>v[j+1] && k[j]<=k[j+1]){
                changed = true;
                k[j]++;
            }

            if(v[j]>v[j-1] && k[j]<=k[j-1]){
                changed = true;
                k[j]++;
            }
        }

        if(!changed)break;
    }

    if(v[0]>v[1])k[0]=k[1]+1;
    if(v[n-1]>v[n-2])k[n-1]=k[n-2]+1;

    cout << accumulate(k.begin(),k.end(),0);

    return 0;
}
