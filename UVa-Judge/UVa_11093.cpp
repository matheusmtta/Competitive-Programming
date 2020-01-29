#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	int q = 1;
	while (t--){
		int n; cin >> n;
		
		vector <int> lap, gas;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			gas.push_back(x);
		}

		int mn = 100000000, aux = 0;

		for (int i = 0; i < n; i++){
			int y; cin >> y;
			lap.push_back(y);
			aux += gas[i] - lap[i];
			mn = min(mn, aux);
		}

		int i = 0;

		while (mn < 0 && i < n){
			mn -= gas[i] - lap[i];
			i++;
		}

		int ans = i + 1;

		cout << "Case " << q << ": ";
		if (i == n || aux < 0) cout << "Not possible" << endl;
		else cout << "Possible from station " << ans << endl;
		
		q++; 
	}
}