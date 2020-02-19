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

int R, C, N;

bool allow(int r, int c){
	if (r >= R || r < 0) return false;
	if (c >= C || c < 0) return false;
	return true;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true){
		int n, m; cin >> n >> m;

		if (n == 0 && m == 0) break;

		bitset <1000005> days;

		bool ans = true;

		for (int i = 0; i < n; i++){
			int l, r; cin >> l >> r;

			for (int j = l; j < r; j++){
				if (!ans) break;
				if (days[j]) ans = false;
				days[j] = 1;
			} 
		}

		for (int i = 0; i < m; i++){
			int l, r, m; cin >> l >> r >> m;

			int k = l;
			int e = 0;

			while (ans && l < 1000000){
				for (int j = l; j < r; j++){
					if (days[j]) {ans = false; break;}
					days[j] = 1;
				}
				l += m;
				r = min(1000000, r + m);
			}
		}

		if (ans) cout << "NO CONFLICT" << endl;
		else cout << "CONFLICT" << endl;
	}

	return 0;
}