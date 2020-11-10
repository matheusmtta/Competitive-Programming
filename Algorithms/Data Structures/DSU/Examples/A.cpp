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

struct DSU{
	int n;
	vector <int> p, sz;

	DSU(int n) : n(n) {
		p.resize(n+1, 0);
		sz.resize(n+1, 0);
		build();
	}

	void build(){
		for (int i = 0; i < n+1; i++)
			p[i] = i, sz[i] = 1;
	}

	int find(int a){
		return p[a] = (p[a] == a) ? a : find(p[a]);
	}

	void une(int a, int b){
		a = find(a); b = find(b);
		
		if (a == b) return;
		
		if (sz[a] > sz[b])
			swap(a, b);
		
		sz[b] += sz[a];
		p[a] = b;
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	DSU dsu(n);

	while (m--){
		string cmd; cin >> cmd;
		int a, b; cin >> a >> b;
		if (cmd == "union")
			dsu.une(a, b);
		else
			dsu.find(a) == dsu.find(b) ? cout << "YES" << endl : cout << "NO" << endl;
	}	

	return 0;
}