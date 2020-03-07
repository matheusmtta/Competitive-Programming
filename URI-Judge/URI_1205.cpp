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

int n, m, k;
double p;
map <int, int> mp;
vector <int> graph[MAX];
vector <int> w[MAX];
int d[MAX];

void dijkstra(int s) {
	for (int i = 1; i <= n; i++)
		d[i] = INF;

	d[s] = mp[s];

	priority_queue <pair<int, int>> pq;

	pq.push(make_pair(mp[s], s));

	while (pq.size()){
		int u = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (dist > d[u]) continue;

		for (int i = 0; i < (int) graph[u].size(); i++){
			int v = graph[u][i];
			if (d[v] > d[u] + mp[v]){
				d[v] = d[u] + mp[v];
				pq.push(make_pair(-d[v], v));
			}
		}
	}
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n >> m >> k >> p){
		for (int i = 1; i <= n; i++)
			mp[i] = 0;

		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		int c; cin >> c;

		for (int i = 0; i < c; i++){
			int x; cin >> x;
			mp[x]++;
		}

		int s, f; cin >> s >> f;

		dijkstra(s);

		int sd = d[f];

		cout << fixed << setprecision(3);

		if (sd > k) cout << "0.000" << endl;
		else {
			double ans = 1;
			for (int i = 0; i < sd; i++){
				ans *= p;
			}
			cout << ans << endl;
		}

		mp.clear();
		for (int i = 0; i < MAX; i++){
			graph[i].clear();
			w[i].clear();
		}
	}

	return 0;
}