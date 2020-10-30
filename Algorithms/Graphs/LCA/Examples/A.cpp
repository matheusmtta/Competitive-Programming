#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

struct LCA {
	int n, root;
	vector <int> height, eulerTour, num, log, visited;
	vector <int64> dist;
	vector <vector<int>> graph, spt;
	vector <vector<int64>> wgt;

	LCA(vector<vector<int>> g, vector<vector<int64>> w, int n, int s) : graph(g), wgt(w), n(n), root(s) {
		num.resize(n+1, 0), visited.resize(n+1, 0), height.resize(n+1, 0), dist.resize(n+1, 0);
		
		dfs(root, 0);
		
		int sz = (int)eulerTour.size();
		sparseTable(sz, (int)log2(sz+1)+1);
	}  

	void dfs(int v, int h){
		visited[v] = 1, height[v] = h;
		num[v] = eulerTour.size();
		eulerTour.push_back(v);

		for (int i = 0; i < graph[v].size(); i++){
			int u = graph[v][i];
			if (!visited[u]){
				dist[u] = dist[v] + wgt[v][i];
				dfs(u, h+1);
				eulerTour.push_back(v);
			}
		}
	}

	void sparseTable(int m, int k){
		spt.resize(m+1, vector<int>(k+1, 0));
		log.resize(m+1, 0);

		for (int i = 2; i <= m; i++) log[i] = log[i/2] + 1;
		
		for (int i = 0; i < m; i++)
			spt[i][0] = eulerTour[i];

		for (int j = 1; j <= k; j++){
			for (int i = 0; i + (1 << j) <= m; i++){
				int h1 = height[spt[i][j-1]];
				int h2 = height[spt[i+(1 << (j-1))][j-1]];
				spt[i][j] = h1 < h2 ? spt[i][j-1] : spt[i+(1 << (j-1))][j-1];
			}
		}
	}

	int64 lca(int a, int b) {  
		int lx = num[a], rx = num[b];
		if (lx > rx) swap(rx, lx);

		int c = log[rx - lx + 1];
		int w = min(spt[lx][c], spt[rx - (1 << c) + 1][c]);

		return dist[a]+dist[b]-(2*dist[w]);
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin >> n){
		if (n == 0) return 0;
		vector<vector<int>> g;
		vector<vector<int64>> w;

		g.resize(n, vector<int>());
		w.resize(n, vector<int64>());

		for (int i = 1; i < n; i++){
			int a; cin >> a;
			int64 p; cin >> p;

			g[i].push_back(a);
			g[a].push_back(i);

			w[i].push_back(p);
			w[a].push_back(p);
		}

		LCA tree(g, w, n, 0);

		int q; cin >> q;

		while (q--){
			int x, y; cin >> x >> y;
			cout << tree.lca(x, y);
			if (q) cout << " ";
		}
		cout << endl;
	}
	

	return 0;
}