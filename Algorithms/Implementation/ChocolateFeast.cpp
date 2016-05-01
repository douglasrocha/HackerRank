#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t,n,c,m;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        int answer=0;
        
        int nc = n / c;
        answer += nc;
        while(nc >= m) {
            ++answer;
            nc -= m - 1;
        }
        
        cout<<answer<<endl;
    }
    return 0;
}
