#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){
	while (1){
		int n, m;
		while (1){
			cin >> n >> m;
			if (n == 0 && m == 0) return 0;

			char mtx[n][n], mtx_nov[m][m],
				 mtx_ctoi[m][m], mtx_dse[m][m];
			char submtx_zero[m][m];

			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					cin >> mtx[i][j];
				}
			}

			for (int i = 0; i < m; i++){
				for (int j = 0; j < m; j++){
					cin >> submtx_zero[i][j];
				}
			}

			int k, l;

			k = m-1;

			for (int i = 0; i < m; i++){
				for (int j = 0; j < m; j++){
					mtx_nov[i][j] = submtx_zero[k][i];
					k--;
				}
				k = m - 1;
			}

			k = m-1; l = m-1;

			for (int i = 0; i < m; i++){
				l = m-1;
				for (int j = 0; j < m; j++){
					mtx_ctoi[i][j] = submtx_zero[k][l];
					l--;
				}
				k--;
			}

			k = m-1;

			for (int i = 0; i < m; i++){
				for (int j = 0; j < m; j++){
					mtx_dse[i][j] = submtx_zero[j][k];
				}
				k--;
			}

			int a = 0, b = 0, c = 0, d = 0;

			for (int i = 0; i < n-m+1; i++){
				for (int j = 0; j < n-m+1; j++){
					int sum = 0;
					for (int s = 0; s < m; s++){
						for (int t = 0; t < m; t++){
							int idi = i + s;
							int idj = j + t;
							if (mtx[idi][idj] == submtx_zero[s][t]){
								sum++;
							}
						}
					}
					if (sum == m*m) a++;
				}
			}

			for (int i = 0; i < n-m+1; i++){
				for (int j = 0; j < n-m+1; j++){
					int sum = 0;
					for (int s = 0; s < m; s++){
						for (int t = 0; t < m; t++){
							int idi = i + s;
							int idj = j + t;
							if (mtx[idi][idj] == mtx_nov[s][t]){
								sum++;
							}
						}
					}
					if (sum == m*m) b++;
				}
			}

			for (int i = 0; i < n-m+1; i++){
				for (int j = 0; j < n-m+1; j++){
					int sum = 0;
					for (int s = 0; s < m; s++){
						for (int t = 0; t < m; t++){
							int idi = i + s;
							int idj = j + t;
							if (mtx[idi][idj] == mtx_ctoi[s][t]){
								sum++;
							}
						}
					}
					if (sum == m*m) c++;
				}
			}

			for (int i = 0; i < n-m+1; i++){
				for (int j = 0; j < n-m+1; j++){
					int sum = 0;
					for (int s = 0; s < m; s++){
						for (int t = 0; t < m; t++){
							int idi = i + s;
							int idj = j + t;
							if (mtx[idi][idj] == mtx_dse[s][t]){
								sum++;
							}
						}
					}
					if (sum == m*m) d++;
				}
			}

			cout << a << " " << b << " " << c << " " << d << endl;
		}
	}

	return 0;
}