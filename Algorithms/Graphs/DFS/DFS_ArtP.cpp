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

//Find all articulation points of a graph in O(V+E) time,
//A vertex is articulation point if, one of the following holds
//1) The vertex is root and has to children
//2) The vertex has no Back Edge to one of its ancestors, therefore,
//have highest low-link.

const int MAX = 100100;

int n, m;
vector <int> graph[MAX];
int timer = 0;
vector <int> visited(MAX, 0);
vector <int> num(MAX), low(MAX, 0);
set <int> artp;

void dfsAP(int v, int p){
	visited[v] = 1;
	low[v] = num[v] = timer++;
	int child = 0;

	for (auto to : graph[v]){
		if (to == p) continue;
		if (visited[to]){
			low[v] = min(low[v], num[to]);
		}
		else {
			dfsAP(to, v);
			low[v] = min(low[v], low[to]);

			if (low[to] >= num[v] && p != -1)
				artp.insert(v);
			child++;
		}
	}
	if (p == -1 && child > 1)
		artp.insert(v);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	//build graph
	for (int i = 0; i < m; i++){
		int x, y, s; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 0; i < n; i++){
		num[i] = -1;
		low[i] = -1;
		visited[i] = 0;
	}

	for (int i = 0; i < n; i++){
		dfsAP(i, -1); //Find articulation points
	}

	return 0;
}