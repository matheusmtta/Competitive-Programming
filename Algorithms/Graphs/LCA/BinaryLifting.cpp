#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

struct LCA {
	int n, k, root, timer = 0;
	vector <int> in, out, height;
	vector <int64> d;
	vector <vector<pair<int, int>>> graph;
	vector <vector<int>> up;

	LCA(int n, int s) : n(n), root(s) {
		graph.resize(n+1, vector<pair<int, int>>());
		out.resize(n+1, 0), in.resize(n+1, 0), d.resize(n+1, 0);
		height.resize(n+1, 0);

		k = ceil(log2(n));
		up.resize(n+1, vector<int>(k+1));

		dfs(root, root, 0);
	}  

	void add_edge(int a, int b, int w){
		graph[a].push_back({b, w});
	}

	bool isAncestor(int a, int b){ 
		return in[a] <= in[b] && out[a] >= out[b]; 
	}

	void dfs() {dfs(root, root, 0);}
	void dfs(int v, int p, int h){
		in[v] = timer++;
		height[v] = h;
		up[v][0] = p;

		for (int i = 1; i <= k; i++)
			up[v][i] = up[up[v][i-1]][i-1];

		for (auto u : graph[v]){
			if (u.first != p) {
				d[u.first] = d[v] + u.second;
				dfs(u.first, v, h+1);
			}
		}

		out[v] = timer++;
	}

	int lca(int a, int b) {  
		if (isAncestor(a, b)) return a;
		if (isAncestor(b, a)) return b;
		
		for (int i = k; i >= 0; i--)
			if (!isAncestor(up[a][i], b))
				a = up[a][i];

		return up[a][0];
	}

	int64 dist(int a, int b){
		int _lca = lca(a, b);
		return d[a] + d[b] - (2*d[_lca]);
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	int n, a, b, w; cin >> n;
		
	LCA tree(n, 0);
	tree.add_edge(a, b, w);
	tree.add_edge(b, a, w);
	tree.dfs();

	return 0;
}