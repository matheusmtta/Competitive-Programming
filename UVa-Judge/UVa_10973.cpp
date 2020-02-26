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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		bitset<3005> graph[3005];
		int n, m; cin >> n >> m;

		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;

			graph[x][y] = 1;
			graph[y][x] = 1;
		}

		int ans = 0;

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (graph[i][j] && i > j){
					bitset <3005> temp = graph[i] & graph[j];
					ans += temp.count();
				}
			}
		}

		cout << ans/3 << endl;
	}

	return 0;
}