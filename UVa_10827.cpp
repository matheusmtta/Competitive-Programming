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
		int n; cin >> n;
		vector <vector<int64>> mtx(400, vector<int64>(400, 0)),
							   summtx(400, vector<int64>(400, 0));

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> mtx[i][j];

		for (int i = 1; i <= 2*n; i++)
			for (int j = 1; j <= 2*n; j++)
				summtx[i][j] = mtx[(i-1)%n+1][(j-1)%n+1] 
						     + summtx[i-1][j]
							 + summtx[i][j-1]
							 - summtx[i-1][j-1];

		int64 ans = -INF;

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				for (int r = 1; r <= n; r++){
					for (int c = 1; c <= n; c++){
						if (i+r <= 2*n && j+c <= 2*n){
							ans = max(ans, summtx[i+r][j+c] -
										   summtx[i][j+c]   - 
										   summtx[i+r][j]  +
										   summtx[i][j]);
						}
					}
				}
			}
		}


		cout << ans << endl;
	}	
		
	return 0;
}