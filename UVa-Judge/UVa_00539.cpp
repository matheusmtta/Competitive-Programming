#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 30;

vector <int> graph[MAX];
int visited[MAX][MAX];

int solve(int v){
	int mx = 0;
	for (int i = 0; i < graph[v].size(); i++){
		if (!visited[v][graph[v][i]]){
			visited[v][graph[v][i]] = 1;
			visited[graph[v][i]][v] = 1;
			mx = max(mx, 1 + solve(graph[v][i]));
			visited[v][graph[v][i]] = 0;
			visited[graph[v][i]][v] = 0;
		}
	}

	return mx;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	while (true){
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
			visited[x][y] = 0;
			visited[y][x] = 0;
		}

		int ans = 0;

		for (int i = 0; i < n; i++)
			ans = max(solve(i), ans);

		cout << ans << endl;

		for (int i = 0; i < n; i++)
			graph[i].clear();
	}

	return 0;
}