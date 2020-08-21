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
	int q = 1;

	while (t--){	
		int n, m; cin >> n >> m;
		int64 k; cin >> k;

		vector <vector<int64>> mtx(200, vector<int64>(200, 0));

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> mtx[i][j];
				mtx[i][j] += mtx[i-1][j];
				mtx[i][j] += mtx[i][j-1];
				mtx[i][j] -= mtx[i-1][j-1];
			}
		}

		int dim = 0;
		int64 price = LINF;

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				for (int r = i; r <= n; r++){
					for (int c = j; c <= m; c++){
						int d = (r-i+1)*(c-j+1);
						int64 curr = mtx[r][c];
						curr -= mtx[r][j-1];
						curr -= mtx[i-1][c];
						curr += mtx[i-1][j-1];
						if (curr <= k && (dim < d || (dim == d && curr < price))){
							dim = d;
							price = curr;
						}
					}
				}
			}
		}

		price = dim > 0 ? price : 0;

		cout << "Case #" << q++ << ": " << dim << " " << price << endl;
	}

	return 0;
}