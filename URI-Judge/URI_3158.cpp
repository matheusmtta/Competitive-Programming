#include <bits/stdc++.h>

#define MOD 1000000007
#define endl "\n"
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

using namespace std;

int dfs(int u, vector< vector<int> > &graph, vector <int> &visited) {
	if (visited[u]) 
		return 0;

	int adjCount = 0;

	visited[u] = 1;

	for (int v : graph[u])
		if (!visited[v])
			adjCount += 1 + dfs(v, graph, visited); 

	return adjCount;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--) {
		int n, m, b, e; cin >> n >> m >> b >> e;

		vector < vector< int> > graph(n);

		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;

			a--; b--;

			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		int64 ans = 0;

		for (int i = 0; i < n; i++) {
			int adjCount = 0;
			if (!visited[i]) {
				 adjCount += dfs(i, graph, visited);

				if (e < b) 
					ans += (e*adjCount) + b;
				else
					ans += b*(adjCount+1);
			}
		}

		cout << ans << endl;
	}

	return 0;
}