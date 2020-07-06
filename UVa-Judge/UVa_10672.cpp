#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
//#define mp make_pair
#define pb push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> graph(10010);
vector <int> visited(10010);
vector <int> parent(10010);
unordered_map <int, int> mp;
int ans = 0, n;

void bfs(){
	queue <int> q;
	for (int i = 1; i <= n; i++){
		if (graph[i] == 1)
			q.push(i);
	}

	while (!q.empty()){
		int v = q.front(); q.pop();
		mp[parent[v]] += mp[v]-1;
		graph[parent[v]]--;
		if (graph[parent[v]] == 1) 
			q.push(parent[v]);
		ans += abs(mp[v]-1);
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n){
		if (n == 0) return 0;
		for (int i = 0; i < n; i++){
			int v; cin >> v;
			int m; cin >> m;
			mp[v] = m;
			int c; cin >> c;
			graph[v] += c;
			for (int j = 0; j < c; j++){
				int u; cin >> u;
				parent[u] = v;
				graph[u] += 1;
			}
		}

		bfs();

		cout << ans << endl;

		for (int i = 0; i < 10010; i++)
			graph[i] = visited[i] = parent[i] = 0;
		mp.clear();
		ans = 0;
	}

	return 0;
}