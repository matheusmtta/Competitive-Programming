 
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

const int MAX = 30005;

int p[MAX], sz[MAX];

void build();
int find(int k);
void une(int a, int b);

void build(){
	for (int i = 0; i < MAX; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(int k){
	if (k == p[k]) return k;
	return find(p[k]);
}

void une(int a, int b){
	a = find(a), b = find(b);

	if (a == b) return;

	if (sz[a] > sz[b]) swap(a, b);

	sz[b] += sz[a];
	p[a] = b;
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		build();
		int n, m; cin >> n >> m;

		while (m--){
			int x, y; cin >> x >> y;
			une(x, y);
		}

		int ans = -1;

		for (int i = 1; i <= n; i++){
			if (sz[i] > ans) ans = sz[i];
		}

		cout << ans << endl;
	}

	return 0;
}