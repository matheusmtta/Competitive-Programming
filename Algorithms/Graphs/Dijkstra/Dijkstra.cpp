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

//Find the distance from the source vertex to all others
//in O(ElogV+V) time.

#define MAX 200000

int n, m;
vector <int> graph[MAX];
vector <int> parent(MAX, -1);
vector <int> w[MAX];
vector <int> d(MAX);

void dijkstra(int ss){
	for (int i = 0; i <= n; i++)
		d[i] = INF;

	d[ss] = 0;
	priority_queue <pair<int, int>> pq;
	pq.push({0, ss});

	while (pq.size()){
		int u = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (dist > d[u])
			continue;

		for (int i = 0; i < (int)graph[u].size(); i++){
			int v = graph[u][i];
			if (d[v] > dist + w[u][i]){
				d[v] = d[u] + w[u][i];
				parent[v] = u;
				pq.push({-d[v], v});
			}
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < m; i++){
		int x, y, s; cin >> x >> y >> s;
		graph[x].push_back(y);
		graph[y].push_back(x);
		w[x].push_back(s);
		w[y].push_back(s);
	}

	int source = 1;

	dijkstra(1);

	int v = n;
	stack <int> st;

	while (v != -1){
		st.push(v);
		v = parent[v];
	}

	while (!st.empty()){
		cout << st.top() << ' ';
		st.pop();
	}
	cout << endl;
	
	return 0;
}