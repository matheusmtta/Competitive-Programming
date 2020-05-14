#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	while (cin >> n >> m){
		if (n == 0 && m == 0) return 0;

		vector <int> diag[2000];

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				int x; cin >> x;
				if (j-i < 0){
					diag[1999+j-i].push_back(x);
				}
				else {
					diag[j-i].push_back(x);
				}
			}
		}


		int q; cin >> q;

		while (q--){
			int ans = 0;
			int mn, mx; cin >> mn >> mx;

			for (int i = 0; i < 2000; i++){
				if (diag[i].size() == 0) continue;
				if (diag[i][0] > mx) continue;
				if (diag[i][diag[i].size()-1] < mn) continue;
				if (ans > diag[i].size()) continue;
				
				int a = 0, b = 0;
				bool f1, f2;
				f1 = f2 = false;
				
				int l = 0, r = ((int)diag[i].size())-1;

				while (l <= r){
					int mid = (l+r+1)/2;
					if (diag[i][mid] < mn)
						l = mid + 1;
					else {
						r = mid - 1;
						a = mid;
						f1 = true;
					}
				}

				if (f1){
					for (int j = diag[i].size()-1; j >= a; j--){
						if (diag[i][j] <= mx){
							b = j;
							break;
						}
					}
					ans = max(ans, b-a+1);
				}
			}
			cout << ans << endl;			
		}
		cout << "-" << endl;
	}	

	return 0;
}