#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> graph[300];
vector <int> visited(300, 0);

void dfs(int v){
	if (v < 110) 
		visited[v] = 1;
	for (int i = 0; i < graph[v].size(); i++)
		if (!visited[graph[v][i]])
			dfs(graph[v][i]);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	int aux = 0, ans = 0;

	for (int i = 1; i <= n; i++){
		int k; cin >> k;
		if (k == 0) {
			aux++;
		}
		for (int j = 0; j < k; j++){
			int x; cin >> x;
			graph[i].push_back(x+110);
			graph[x+110].push_back(i);
		}
	}


	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			ans++;
			dfs(i);
		}
	}

	ans = aux == n ? aux : ans-1;

	cout << ans << endl;

	return 0;
}