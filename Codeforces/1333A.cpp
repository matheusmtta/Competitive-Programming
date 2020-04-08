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

	int t; cin >> t;

	while (t--){
		int n, m; cin >> n >> m;

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (i == 0 && j == 0) cout << 'W';
				else cout << 'B';
			}
			cout << endl;
		}
	}

	return 0;
}