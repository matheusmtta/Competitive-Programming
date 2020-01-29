#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	while (1){
		int n, b;
		cin >> n >> b;
		if (n == 0 && b == 0) return 0;

		int l, r;

		int left[100005], right[100005];

		for (int i = 1; i <= n; i++){
			int k = i;
			left[i] = k - 1;
			right[i] = k + 1;
		}

		left[1] = -1;
		right[n] = -1;

		for (int i = 0; i < b; i++){
			cin >> l >> r;

			left[right[r]] = left[l];

			if (left[l] != -1){
				cout << left[l];
			}
			else{
				cout << "*";
			}

			right[left[l]] = right[r];

			if (right[r] != -1){
				cout << " " << right[r] << endl;
			}
			else{
				cout << " *" << endl;
			}
		}

		cout << "-" << endl;
	}
}