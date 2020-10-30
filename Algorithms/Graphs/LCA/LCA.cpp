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
	vector <vector<int>> graph, spt;

	LCA(vector<vector<int>> g, int n, int s) : graph(g), n(n), root(s) {
		num.resize(n+1, 0), visited.resize(n+1, 0), height.resize(n+1, 0);

		dfs(root, 0);
		int sz = (int)eulerTour.size();
		sparseTable(sz, (int)log2(sz+1)+1);
	}  

	void dfs(int v, int h){
		visited[v] = 1, height[v] = h;
		num[v] = eulerTour.size();
		eulerTour.push_back(v);

		for (auto u : graph[v]){
			if (!visited[u]){
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

	int lca(int a, int b) {  
		int lx = num[a], rx = num[b];
		if (lx > rx) swap(rx, lx);

		int c = log[rx - lx + 1];
		return min(spt[lx][c], spt[rx - (1 << c) + 1][c]);
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, u, v;
	vector<vector<int>> g;

	LCA tree(g, n, 0);
	tree.lca(u, v);

	return 0;
}
