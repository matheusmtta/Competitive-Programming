#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	while (1){
		cin >> t; if (t == 0) return 0;
		vector <int> hw(1, 1422+100);

		for (int i = 0; i < t; i++){
			int x; cin >> x;
			hw.push_back(x);
		}

		sort(hw.begin(), hw.end());

		vector <int> diff;

		bool ans = true;

		for (int i = 0; i < hw.size()-1; i++){
			int aux = hw[i+1] - hw[i];
			if (aux > 200) ans = false;
		}

		if (ans) cout << "POSSIBLE" << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
}