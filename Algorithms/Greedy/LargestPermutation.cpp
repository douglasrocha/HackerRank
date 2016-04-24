#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef unsigned long long int ull;
typedef pair<ull, ull> p_ull;

int compare(const void * lhs, const void * rhs)
{
    if ((*(p_ull*)lhs).first == (*(p_ull*)rhs).first) {
        return (*(p_ull*)lhs).second - (*(p_ull*)rhs).second;
    }

    return (*(p_ull*)lhs).first - (*(p_ull*)rhs).first;
}

ull binary_find(p_ull* arr, ull begin, ull end, ull value)
{
	ull middle = -1;
	while (begin < end) {
		middle = begin + ((end - begin) / 2);
		if (value == arr[middle].first) return middle;
		else if (value > arr[middle].first) {
			begin = middle + 1;
		}
		else {
			end = middle - 1;
		}
	}
	if (arr[begin].first == value) return begin;
	return -(begin + 1);
}

int main() {
    ull N, K;
    cin >> N >> K;

    p_ull * vetHeap = new p_ull[N];
    ull pointVet = N-1;

    ull startPosition;
    p_ull max;
    ull maxIndex,maxValue;
    ull valueAux;
    ull indexAux;

    vector<ull> vet(N,0);

    for (ull i=0; i<N; i++){
        cin >> vet[i];
        vetHeap[i] = make_pair(vet[i],i);
    }

    qsort (vetHeap, N, sizeof(p_ull), compare);

    for (startPosition = 0; startPosition < K; startPosition++){
        if (startPosition >= N) break;

        maxValue = vetHeap[pointVet].first;
        maxIndex = vetHeap[pointVet].second;
        pointVet--;

        if (maxIndex == startPosition){
            K++;
            continue;
        }

        valueAux = vet[startPosition];
        vet[startPosition] = maxValue;
        vet[maxIndex] = valueAux;

        indexAux = binary_find(vetHeap, 0, pointVet, valueAux);
        vetHeap[indexAux].second = maxIndex;
    }

    for (ull i = 0; i < N; i++){
        if (i > 0) cout << " ";
        cout << vet[i];
    }

    return 0;
}
