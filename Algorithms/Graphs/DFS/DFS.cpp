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

//Depth First Search O(V+E)

const int MAX = 10000;

vector <int> graph[MAX];
vector <int> visited(MAX);

void DFS(int source){
	visited[source] = 1;

	for (int i = 0; i < graph[source].size(); i++){
		if (!visited[graph[source][i]])
			DFS(graph[source][i]);
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 0; i < n; i++){
		if (!visited[i])
			DFS(i);
	}

	return 0;
}