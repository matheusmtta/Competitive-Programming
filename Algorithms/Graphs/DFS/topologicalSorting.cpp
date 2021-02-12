#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> order, visited;
vector<vector<int>> graph;

void dfs(int v){
	visited[v] = 1;

	for (int u : graph[v]){
		if (visited[u] == 0)
			dfs(u);
	}
	order.push_back(v);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	graph.resize(n);
	visited.assign(n, 0);

	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
	}

	for (int i = 0; i < n; i++)
		if (!visited[i])
			dfs(i);

	reverse(order.begin(), order.end());

	return 0;
}