#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, t, p;
int64 memo[500][500];

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c; cin >> c;
	while (c--){
		cin >> n >> t >> p;
		memset(memo, 0, sizeof memo);
 	
		memo[0][0] = 1;

		for (int i = 1; i <= n; i++)
			for (int j = p; j <= t; j++)
				for (int l = p; l <= j; l++)
					memo[i][j] += memo[i-1][j - l];

		// for (int i = 0; i <= n; i++){
		// 	for (int j = 0; j <= k; j++){
		// 		cout << memo[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }

		cout << memo[n][t] << endl;
	}

	return 0;
}