#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 1010;

int n, m;
vector <int> graph[MAX];
vector <int> w[MAX];
int d[MAX];

void dijkstra(int s) {
	for (int i = 1; i <= n; i++)
		d[i] = INF;
	d[s] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, s));

	while (pq.size()) {
		int u = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		if (dist > d[u]) continue;

		for (int i = 0; i < (int) graph[u].size(); i++) {
			int v = graph[u][i];
			if (d[v] > d[u] + w[u][i]) {
				d[v] = d[u] + w[u][i];
				pq.push(make_pair(-d[v], v));
			}
		}
	}
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int x, y, p; cin >> x >> y >> p;
		graph[x].push_back(y);
		graph[y].push_back(x);
		w[x].push_back(p);
		w[y].push_back(p);
	}

	int k; cin >> k;

	dijkstra(k);

	int ans1 = -1, ans2 = INF;

	for (int i = 1; i <= n; i++){
		if (d[i] != 0) ans1 = max(ans1, d[i]), ans2 = min(ans2, d[i]);
	}

	cout << ans1 - ans2 << endl;

	return 0;
}