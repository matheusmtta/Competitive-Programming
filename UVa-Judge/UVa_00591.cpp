#include <bits/stdc++.h>

using namespace std;

int main(){

	int n; int q = 1;
	while (1){
		cin >> n;
		if (n == 0) return 0;

		int vec[n], sum = 0;

		for (int i = 0; i < n; i++){
			int x; cin >> x; vec[i] = x;
			sum += x;
		}

		int m = sum/n;

		sum = 0;

		for (int i = 0; i < n; i++){
			sum += abs(vec[i]-m);
		}

		printf("Set #%d\nThe minimum number of moves is %d.\n\n", q, sum/2);
		q++;
	}

	return 0;
}