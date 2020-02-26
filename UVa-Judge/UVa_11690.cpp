 
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

const int MAX = 10010;

void une(int a, int b);
int find(int k);

int p[MAX];
int64 sz[MAX];

void build(){
	for (int i = 0; i < MAX; i++){
		p[i] = i;
		sz[i] = 0;
	}
}

int find(int k){
	if (k == p[k]) return k;
	return find(p[k]);
}

void une(int a, int b){
	a = find(a), b = find(b);

	if (a == b) return;

	sz[b] += sz[a];
	sz[a] = 0;

	p[a] = b;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n, m; cin >> n >> m;
		build();
		for (int i = 0; i < n; i++){
			cin >> sz[i];
		}

		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			une(x, y);
		}

		bool ans = true;

		for (int i = 0; i < n; i++){
			if (sz[find(i)] != 0) ans = false;
		}

		if (ans) cout << "POSSIBLE" << endl;
		else cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}