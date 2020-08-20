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
		vector <vector<int>> mtx(110, vector<int>(110, 0));
		int m; cin >> m;

		for (int i = 0; i < m; i++){
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			for (int x = x1; x <= x2; x++)
				for (int y = y1; y <= y2; y++)
					mtx[x][y] = 1;
		}

		vector <vector<int>> summtx(110, vector<int>(110, 0));
		
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				summtx[i][j] = mtx[i][j];
				summtx[i][j] += summtx[i-1][j];
				summtx[i][j] += summtx[i][j-1];
				summtx[i][j] -= summtx[i-1][j-1];
			}
		}

		int ans = 0;

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				for (int r = i; r <= n; r++){
					for (int c = j; c <= n; c++){
						int curr = summtx[r][c];
						curr -= summtx[i-1][c];
						curr -= summtx[r][j-1];
						curr += summtx[i-1][j-1];
						if (curr == 0){
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