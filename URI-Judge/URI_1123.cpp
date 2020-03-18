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

const int MAX = 300;

vector <int> graph[MAX];
vector <int> w[MAX];
vector <int> d(MAX);

void dijkstra(int ss){
	for (int i = 0; i <= MAX; i++){
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
			if (d[v] > d[u] + w[u][i]){
				d[v] = d[u] + w[u][i];
				pq.push(MP(-d[v], v));
			}
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true){
		int N, M, C, K; cin >> N >> M >> C >> K;
		
		if (N == 0 && M == 0 && C == 0 && K == 0) return 0;

		for (int i = 0; i < M; i++){
			int x, y, s; cin >> x >> y >> s;

			if (x < C && y >= C){
				graph[y].push_back(x);
				w[y].push_back(s);
			}
			if (x >= C && y < C){
				graph[x].push_back(y);
				w[x].push_back(s);
			}
			if ((x < C && y < C) && abs(x-y)==1){
				graph[y].push_back(x);
				graph[x].push_back(y);
				w[y].push_back(s);
				w[x].push_back(s);
			}
			if (x >= C && y >= C){
				graph[y].push_back(x);
				graph[x].push_back(y);
				w[y].push_back(s);
				w[x].push_back(s);
			}
		}

		dijkstra(K);

		cout << d[C-1] << endl;

		for (int i = 0; i < MAX; i++){
			graph[i].clear();
			w[i].clear();	
		}
	}	

	return 0;
}