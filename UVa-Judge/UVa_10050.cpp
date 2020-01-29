#include <bits/stdc++.h>

using namespace std;

int main(){

	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		int ans = 0;
		bool vec[n+1];

		for (int i = 1; i <= n; i++)
			vec[i] = false;

		int p; cin >> p;

		for (int i = 0; i < p; i++){
			int x; cin >> x;
			for (int j = x; j <= n; j += x){
				if (j%7 != 6 && j%7 != 0)
					vec[j] = true;
			}
		}

		for (int i = 1; i <= n; i++){
			if (vec[i]) ans++;
		}


		cout << ans << endl;
	}

	return 0;
}