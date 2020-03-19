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

int n, m, q;
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

vector <int> disc(MAX);
vector <int> simpleGraph[MAX];
map <int, int> cc;
int ans;

void DFS(int s, int o){
	disc[s] = 1;
	cc[s] = o;

	for (int i = 0; i < simpleGraph[s].size(); i++){
		if (!disc[simpleGraph[s][i]])
			DFS(simpleGraph[s][i], o);
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true){
		timer = 1;
		brdg.clear();
		cc.clear();

		for (int i = 0; i < MAX; i++){
			visited[i] = disc[i] = 0;
			low[i] = num[i] = -1;
			simpleGraph[i].clear();
			graph[i].clear();
		}

		cin >> n >> m >> q;
		
		if (n == 0 && m == 0 && q == 0) exit(0);

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
			int v = brdg[i].first;
			int u = brdg[i].second;

			simpleGraph[v].push_back(u);
			simpleGraph[u].push_back(v);
		}

		int l = 1;

		for (int i = 1; i <= n; i++){
			if (!disc[i]){
				DFS(i, l);
				l++;
			}
		}

		for (int i = 0; i < q; i++){
			int x, y; cin >> x >> y;

			if (cc[x] == cc[y]) cout << "Y" << endl;
			else cout << "N" << endl;
		}
		cout << '-' << endl;
	}

	return 0;
}