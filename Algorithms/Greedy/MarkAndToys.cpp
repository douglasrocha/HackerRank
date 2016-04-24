#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, k; cin >> n >> k;
    vector<int> prices;
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        prices.push_back(p);
    }

    int answer = 0;
    bool boughtSomething = false;

    // Write the code for computing the final answer using n,k,prices
    do {
        boughtSomething = false;
        unsigned long long minimum = 1999999999;
        int indexof = -1;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minimum) {
                minimum = prices[i];
                indexof = i;
            }
        }

        if (minimum < k) {
            k -= minimum;
            answer++;
            prices.erase(prices.begin() + indexof);
            boughtSomething = true;
        }

    } while (boughtSomething);

    cout << answer << endl;

    return 0;
}
