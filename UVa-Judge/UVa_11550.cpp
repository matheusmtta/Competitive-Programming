 
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n, m; cin >> n >> m;

		int mtx[n][m];

		map <pair <int, int>, int> mp;

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				int x; cin >> x;
				mtx[i][j] = x;
			}
		}


		int e = 0, sum = 0;
		bool ans = true;

		int x = -1, y = -1;

		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (mtx[j][i]) sum++;
				if (mtx[j][i] && x == -1) x = j;
				if (mtx[j][i] && x != -1) y = j;
			}

			if (sum == 2) e++;
			if (sum != 0 && sum != 2) ans = false;

			mp[MP(x, y)]++;
			sum = 0;
			x = y = -1;
		}

		for (auto i : mp){
			if (i.second > 1) ans = false;
		}

		if (ans && m == e) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}