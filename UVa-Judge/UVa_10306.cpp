#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int m, s;
		cin >> m >> s;

		vector <pair<int, int>> arr;

		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			arr.push_back({x, y});
		}

		int memo[350][350];

		memset(memo, INF, sizeof memo);

		memo[0][0] = 0;

		for (int i = 0; i < m; i++)
			for (int j = arr[i].first; j <= s; j++)
				for (int k = arr[i].second; k <= s; k++)
					memo[j][k] = min(memo[j][k], 1 + memo[j - arr[i].first][k - arr[i].second]);

		int ans = INF;

		for (int i = 0; i <= s; i++){
			for (int j = 0; j <= s; j++){
				if (i*i + j*j == s*s){
					ans = min(memo[i][j], ans);
				}
			}
		}

		if (ans >= INF)
			cout << "not possible" << endl;
		else
			cout << ans << endl;
	}

	return 0;
}