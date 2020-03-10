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
//Cycle detection------------
map <pair<int, int>, int> wgt;
map <int, int> cw;
vector <int> color(MAX);
vector <int> parents(MAX);
vector <int> mark(MAX);
map <int, int> verCy;
//Dijkstra-------------------
vector <int> w[MAX];
vector <int> d(MAX);

void dfsCycle(int u, int p, int &cyclenumber){
	if (color[u] == 2) return;

	if (color[u] == 1 && u != p){
		cyclenumber++;
		int cur = p;
		verCy[p] = cyclenumber;
		verCy[u] = cyclenumber;
		cw[cyclenumber] += wgt[MP(p, u)];
		mark[cur] = cyclenumber;

		while (cur != u){
			cw[cyclenumber] += wgt[MP(cur, parents[cur])];
			verCy[cur] = cyclenumber;
			verCy[parents[cur]] = cyclenumber;
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

void dijkstra(int ss){
	for (int i = 1; i <= n; i++){
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

	while(cin >> n >> m){
		for (int i = 1; i <= n; i++){
			graph[i].clear();
			w[i].clear();
		}


		for (int i = 0; i < m; i++){
			int x, y, s; cin >> x >> y >> s;
			graph[x].push_back(y); graph[y].push_back(x);
			w[x].push_back(s); w[y].push_back(s);
			wgt[MP(x, y)] = wgt[MP(y, x)] = s;
		}
		
		int cn = 0;

		for (int i = 1; i <= n; i++){
			if (!color[i])
				dfsCycle(i, 0, cn);
		}

		int k; cin >> k;

		for (int i = 0; i < k; i++){
			int ans = INF;
			bool rsp = false;
			int ss, tt; cin >> ss >> tt;

			if (verCy.find(ss) != verCy.end()){
				int c = verCy[ss];
				if (cw[c] >= tt) {ans = cw[c]; rsp = true;}
			}

            dijkstra(ss);

			for (auto x : verCy){
				if (cw[x.second] >= tt && d[x.first] != -1){
					ans = min(ans, (2*d[(int)x.first])+cw[x.second]);
					rsp = true;
				}
			}
			if (rsp) cout << ans << endl;
			else cout << -1 << endl;
		}

		for (int i = 0; i <= n; i++){
			mark[i] = parents[i] = color[i] = 0;
			wgt.clear();
			verCy.clear();
			cw.clear();
		}
	}
	

	return 0;
}