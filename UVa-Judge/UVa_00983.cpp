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
		if (q) cout << endl;

		vector <vector<int64>> mtx(1010, vector<int64>(1010, 0));

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				cin >> mtx[i][j];
				mtx[i][j] += mtx[i-1][j];
				mtx[i][j] += mtx[i][j-1];
				mtx[i][j] -= mtx[i-1][j-1];
			}
		}

		vector <int64> ans;
		int64 sum = 0;

		for (int i = 1, k = n - m + 1; i <= k; i++){
			for (int j = 1; j <= k; j++){
				int l, r; 
				l = i+m-1;
				r = j+m-1;
				int64 submtx =   mtx[l][r]
							   - mtx[i-1][r]
							   - mtx[l][j-1]
							   + mtx[i-1][j-1];
				sum += submtx;
				ans.push_back(submtx);
 			}
		}

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
		cout << sum << endl;
		q++;
	}

	return 0;
}