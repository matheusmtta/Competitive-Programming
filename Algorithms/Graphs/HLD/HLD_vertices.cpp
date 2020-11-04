#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
 
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 100010;
 
struct HLD {
	int n, timer;
	vector <vector<int>> graph;
	vector <vector<int>> search;
	vector <int> sz, heavy, parent, pos, val, arr;
 
	HLD(int n) : n(n) {
		sz.assign(n+1, 0), 
		heavy.resize(n+1, -1), 
		parent.assign(n+1, 0), 
		pos.assign(n+1, 0);
		val.assign(n+1, 0);
		arr.assign(n+1, 0);

		graph.resize(n+1, vector<int>());
	}
 
	void build() {
		timer = 0;
		heavy[0] = 0;
		dfs(0);

		buildHLTree(0);

		search.resize(timer+1, vector<int>());
		for (int i = 0; i < timer; i++)
			search[arr[i]].push_back(i);
	}
 
	void add_edge(int u, int v){ graph[u].push_back(v); }
 
	void dfs(int v, int p = -1){
		sz[v] = 1;
		for (int &u : graph[v]) {
			if (u != p){
				dfs(u, v);
				sz[v] += sz[u]; 
				if (sz[u] > sz[graph[v][0]])
					swap(u, graph[v][0]);
			}
		}
	}
	
	void buildHLTree(int v, int p = -1){
		pos[v] = timer++;
		arr[pos[v]] = val[v];
		for (int u : graph[v]){
			if (u != p){
				parent[u] = v;
				heavy[u] = (u == graph[v][0] ? heavy[v] : u);
				buildHLTree(u, v);
			}
		}
	}
 
	int query(int a, int b){
		if (pos[a] < pos[b])
			swap(a, b);
		if (heavy[a] == heavy[b])
			return find(pos[b], pos[a]);
		return find(pos[heavy[a]], pos[a]) + query(parent[heavy[a]], b);
	}

	int find(int a, int b){
		return 1;
	}
};
 
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, a, b;
	HLD tree(MAX);
	for (int i = 0; i < n; i++)
		cin >> tree.val[i];
	tree.add_edge(a, b);
	tree.add_edge(b, a);
	tree.build();
	tree.query(a, b);
 
	return 0;
} 