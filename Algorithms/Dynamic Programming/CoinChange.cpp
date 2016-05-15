#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;

ll coin_change(ll n, vector<ll> coins) {
    vector<ll> v(n + 1, 0);
    v[0] = 1;
    
    for (int i = 0; i < coins.size(); i++) 
        for (int j = coins[i]; j <= n; j++) 
            v[j] += v[j-coins[i]];
        
    return v[n];
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(m, 0);
    for (ll i = 0; i < m; i++) cin >> v[i];    
    cout << coin_change(n, v);
    return 0;
}

