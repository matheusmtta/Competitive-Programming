#include <bits/stdc++.h>
 
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

	int n, m, k;

	while (cin >> n >> m >> k){
		if (n == 0 && m == 0 && k == 0) exit(0);
		int mtx[320][320];

		memset(mtx, 0, sizeof mtx);

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				char aux; cin >> aux;
				aux == '.' ? mtx[i][j] = 1 : mtx[i][j] = 0;
				mtx[i][j] += mtx[i][j-1];
			}
		}

		int ans = INF;

		for (int l = 1; l <= m; l++){
			for (int r = l; r <= m; r++){
				vector <int> tmp(n+1, 0);
				for (int i = 1; i <= n; i++)
					tmp[i] = mtx[i][r] - mtx[i][l-1] + tmp[i-1];
				for (int i = 1; i <= n; i++){
					int start = 1, finish = i;
					int curr = tmp[i];
					if (curr >= k){
						curr -= k;
						int x = 0, y = n;
						while (x <= y){
							int mid = (x+y)/2;
							if (tmp[mid] > curr){
								y = mid - 1;
							}
							else {
								start = mid;
								x = mid + 1;
							}
						}
						ans = min((r-l+1)*(finish-start), ans);
					}
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}