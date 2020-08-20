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


	int n, m, q = 0;
	while (cin >> n >> m){
		if (n == 0 && m == 0) exit(0);
		if (q) cout << endl;

		vector <vector<int64>> mtx(110, vector<int64>(110, 0));

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> mtx[i][j];
				mtx[i][j] += mtx[i-1][j];
				mtx[i][j] += mtx[i][j-1];
				mtx[i][j] -= mtx[i-1][j-1];
			}
		}

		int ans = 0;

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				for (int r = i; r <= n; r++){
					for (int c = j; c <= m; c++){
						int submtx = mtx[r][c];
						submtx -= mtx[i-1][c];
						submtx -= mtx[r][j-1];
						submtx += mtx[i-1][j-1];
						if (submtx == 0){
							ans = max(ans, (r-i+1)*(c-j+1));
						}
					}
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}