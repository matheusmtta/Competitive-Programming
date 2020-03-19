 #include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 600;

int timer = 0;
int n, m;
vector <int> graph[MAX];
vector <int> d(MAX);
map <pair<int, int>, int> edges;

void dijkstra(int ss){
	for (int i = 0; i <= n; i++){
		d[i] = INF;
	}
	d[ss] = 0;
	priority_queue <pair <int, int>> pq;
	pq.push(MP(0, ss));

	while (pq.size()){
		int u = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (dist > d[u]) continue;
	
		for (int i = 0; i < (int)graph[u].size(); i++){
			int v = graph[u][i];
			pair <int, int> tmp = MP(u,v);
			if (d[v] > d[u] + edges[tmp]){
				d[v] = d[u] + edges[tmp];
				pq.push(MP(-d[v], v));
			}
		}
	}
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (true){
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		for (int i = 0; i <= n; i++){
			graph[i].clear();
		}
		d.clear();
		edges.clear();

		for (int i = 0; i < m; i++){
			int x, y, s; cin >> x >> y >> s;
			graph[x].push_back(y);
			edges[MP(x, y)] = s;

			if (edges.find(MP(y, x)) != edges.end()){
				edges[MP(x, y)] = 0;				
				edges[MP(y, x)] = 0;
			}
		}

		int k; cin >> k;

		for (int i = 0; i < k; i++){
			int org, dest;
			cin >> org >> dest;
			dijkstra(org);

			if (d[dest] != INF) cout << d[dest] << endl;
			else cout << "Nao e possivel entregar a carta" << endl;
		}
		cout << endl;
	}
	
	return 0;
}