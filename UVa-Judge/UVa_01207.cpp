#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; string a, b;
	while (cin >> n >> a){
		cin >> m >> b;

		int memo[m+1][n+1];
		memset(memo, 0, sizeof memo);
	
		for (int i = 0; i <= m; i++)
			memo[0][i] = i;
		for (int j = 0; j <= n; j++)
			memo[j][0] = j;

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (a[i-1] == b[j-1])
					memo[i][j] = memo[i-1][j-1];
				else{
					int insert = memo[i][j-1];
					int remove = memo[i-1][j];
					int replace = memo[i-1][j-1];

					memo[i][j] = 1 + min({insert, remove, replace});
				}
			}
		}

		//for (int i = 0; i <= n; i++){
		//	for (int j =0; j <= m; j++)
		//		cout << memo[i][j] << ' ';
		//	cout << endl;
		//}

		cout << memo[n][m] << endl;
	}

	return 0;
}