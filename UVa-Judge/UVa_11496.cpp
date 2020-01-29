#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1){
		int n, x; cin >> n;
		int ans = 0;
		if (n == 0) return 0;
		vector <int> music;
		for (int i = 0; i < n; i++){
			cin >> x; music.push_back(x);
		}

		if (music.size() == 2){ 
			if (music[0] != music[1]){
			 	ans = 2;
			}
			else ans = 0;
		}
		else {
			for (int i = 0; i < music.size(); i++){
				int l = music[(i-1)%n];
				if (i == 0) l = music[n-1];
				int r = music[(i+1)%n];
				if (i == n-1) r = music[0];
				int c = music[i];

				//cout << l << " " << c << " " << r << endl;

				if (c > l && c > r) ans++;
				else if (c < l && c < r) ans++;
			}
		}

		cout << ans << endl;
	}
}