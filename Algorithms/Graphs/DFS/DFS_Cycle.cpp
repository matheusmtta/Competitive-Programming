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

const int MAX = 100100;

int n, m;
vector <int> graph[MAX];
map <pair<int, int>, int> wgt;
vector <int> color(MAX);
vector <int> parents(MAX);
vector <int> mark(MAX);
//map <int, int> cw;
//map <int, int> verCy;

//Find all cycles in a graph (O(V+E)), the commented lines
//can be used to find the weight of each cycle in weighted
//graph

void dfsCycle(int u, int p, int &cyclenumber){
	if (color[u] == 2) return;

	if (color[u] == 1 && u != p){
		cyclenumber++;
		int cur = p;
		//verCy[p] = cyclenumber;
		//verCy[u] = cyclenumber;
		//cw[cyclenumber] += wgt[MP(p, u)];
		mark[cur] = cyclenumber;

		while (cur != u){
			//cw[cyclenumber] += wgt[MP(cur, parents[cur])];
			//verCy[cur] = cyclenumber;
			//verCy[parents[cur]] = cyclenumber;
			cur = parents[cur];
			mark[cur] = cyclenumber;
		}
		return;
	}

	parents[u] = p;

	color[u] = 1;

	for (int v : graph[u]){
		if (v == parents[u] && color[v])
			continue;
		dfsCycle(v, u, cyclenumber);
	}

	color[u] = 2;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < m; i++){
		int x, y, s; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		// w[x].push_back(s);
		// w[y].push_back(s);
		//wgt[MP(x, y)] = wgt[MP(y, x)] = s;
	}
		
	int cn = 0;

	for (int i = 1; i <= n; i++){
		if (!color[i])
			dfsCycle(i, 0, cn);
	}

	return 0;
}