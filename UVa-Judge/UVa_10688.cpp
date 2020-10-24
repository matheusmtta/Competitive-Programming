#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, q = 1; cin >> t;

	while (t--){
		cout << "Case " << q << ": ";
		int n, k; cin >> n >> k;

		vector <vector <int>> memo(510, vector<int>(510, 0));

		for (int i = n; i >= 1; i--){
			for (int j = i + 1; j <= n; j++){
				memo[i][j] = INF;
				for (int c = i; c <= j; c++){
					memo[i][j] = min({memo[i][j], (j - i + 1)*(k + c) + memo[c+1][j] + memo[i][c-1]});
				}
			}
		}

		cout << memo[1][n] << endl;
		q++;
	}

	return 0;
}