#include <bits/stdc++.h>

using namespace std;

//COMPLEXITY O(N + M)

//GRAPH ADJACENCY LIST,
//NUMBER OF VERTICES AND
//SOURCE VERTEX
vector < vector <int> > graph;
int n; int s;

//VERTICES ADJACENCY SEARCH
//QUEUE AND PARENTS, DISTANCE
//AND VISITED PARAMETERS
queue <int> q;
vector <int> d(n, 0), p(n, 0);
vector <bool> visited(n, 0);

void BFS(int source){
	q.push(source);
	visited[source] = true;
	p[source] = -1;

	while (!q.empty()){
		int v = q.front();
		q.pop();

		for (int u = 0; u < graph[v].size(); u++){
			if (!visited[graph[v][u]]){
				visited[graph[v][u]] = true;
				q.push(graph[v][u]);
				d[graph[v][u]] = d[v] + 1;
				p[graph[v][u]] = v;
			}
		}
	}
}