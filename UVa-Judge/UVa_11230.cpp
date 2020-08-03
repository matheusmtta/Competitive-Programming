#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r, c; 
	while (cin >> n >> m >> r >> c){
		if (n == 0 && m == 0 && c == 0 && r == 0) return 0;
		char mtx[200][200], mymtx[200][200];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> mtx[i][j];
				mymtx[i][j] = '0';
			}
		}
		int ans = 0;
		for (int i = 0; i < n-r+1; i++){
			for (int j = 0; j < m-c+1; j++){
				if (mtx[i][j] != mymtx[i][j]){
					for (int l = i; l < i+r; l++)
						for (int s = j; s < j+c; s++)
							mymtx[l][s] = mymtx[l][s] == '0' ? '1' : '0';
					ans++;
				}
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (mtx[i][j] != mymtx[i][j])
					ans = -1;
			}
		}

		cout << ans << endl;
	}

	return 0;
}