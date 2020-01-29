#include <bits/stdc++.h>

using namespace std;

int main(){

	int n; cin >> n;
	getchar();

	while(n--){
		int N, K; cin >> N >> K;

		//cout << N << " " << K << endl;

		vector <bool> arr(N+1, false);
		
		for (int i = 0; i < K; i++){
			int x; cin >> x;
			vector <int> p1, p2;
			for (int j = 0; j < x; j++){
				int tmp; cin >> tmp;
				p1.push_back(tmp);
			}

			for (int j = 0; j < x; j++){
				int tmp; cin >> tmp;
				p2.push_back(tmp);
			}

			char op; cin >> op;
			if (op == '='){
				for (int j = 0; j < x; j++){
					arr[p1[j]] = true;
					arr[p2[j]] = true;
				}
			}
			else {
				set <int> aux;
				for (int j = 0; j < x; j++){
					aux.insert(p1[j]);
					aux.insert(p2[j]);
				}

				for (int j = 1; j < N+1; j++){
					if (!aux.count(j)) arr[j] = true;
				}
			}
		}

		int count = 0, ans;

		for (int i = 1; i < N+1; i++){
			if (!arr[i]) {count++; ans = i;}
		}

		if (count == 1) cout << ans << endl;
		else cout << 0 << endl;

		if (n) cout << endl;
	}

	return 0;
}