#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 10100;

//Get all graph's bridges in O(V+E)

int n, m;
vector <int> graph[MAX];
vector <pair<int, int>> brdg;
vector <int> num(MAX), low(MAX), visited(MAX);
int timer = 1;

void DFS_Bridges(int v, int p){
	visited[v] = 1;
	num[v] = low[v] = timer;
	timer++;
	for (int i = 0; i < graph[v].size(); i++){
		if (graph[v][i] == p) continue;
		if (visited[graph[v][i]]){
			low[v] = min(low[v], low[graph[v][i]]);
		}
		else {
			DFS_Bridges(graph[v][i], v);
			low[v] = min(low[v], low[graph[v][i]]);
			if (low[graph[v][i]] > num[v]){
				brdg.push_back(MP(v, graph[v][i]));
			}
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < MAX; i++){
		visited[i] = 0;
		low[i] = num[i] = -1;
	}

	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}


	for (int i = 1; i <= n; i++){
		if (!visited[i])
			DFS_Bridges(i, -1);
	}

	for (int i = 0; i < brdg.size(); i++){
		cout << brdg[i].first << " " << brdg[i].second << endl;
	}

	return 0;
}