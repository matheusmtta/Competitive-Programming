#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while (1){
		cin >> n; 
		if (n == 0)
			return 0;

		vector <pair <int, int>> pole;

		int sum = 0;

		vector <int> pos(n+1, 0);

		bool ans = true;

		for (int i = 1; i <= n; i++){
			int idx, p; cin >> idx >> p;
			pole.push_back(make_pair(i+p, idx));
			if (i+p > 0 && i+p <= n) pos[i+p]++;
			else ans = false;
			sum += p;
		}


		for (int i = 1; i <= n; i++)
			if (pos[i] != 1)
				ans = false;

		if (sum != 0 || !ans) cout << -1 << endl;
		else {
			sort(pole.begin(), pole.end());
			for (int i = 0; i < pole.size(); i++){
				cout << pole[i].second;
				if (i != pole.size() - 1) cout << " ";
			}
			cout << endl;
		}
	}
}