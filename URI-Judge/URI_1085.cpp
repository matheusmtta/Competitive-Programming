 
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

map <string, vector <pair<string, string>>> graph;
map <string, int> d;

int dijkstra(string ss){
	d[ss] = 0;
	priority_queue <pair <int, pair<string, string>>, vector<pair <int, pair<string, string>>>, greater<pair <int, pair<string, string>>>>  pq;

	pq.push(MP(0, MP(ss, "*****")));

	while (pq.size()){
		string a = pq.top().second.first;
		string b = pq.top().second.second;
		int dist = pq.top().first;
		pq.pop();

		if (dist > d[a]) continue;

		for (int i = 0; i < (int)graph[a].size(); i++){
			string v = graph[a][i].first;
			string word = graph[a][i].second;
			if (b[0] != word[0] && d[v] > d[a] + (int)word.length()){
				d[v] = d[a] + (int)word.length();
				pq.push(MP(d[v],MP(v, word)));
			}
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true){
		int n; cin >> n;
		if (n == 0) exit(0);
		string org, dest; cin >> org >> dest;

		d[org] = INF;
		d[dest] = INF;

		for (int i = 0; i < n; i++){
			string a, b, c; cin >> a >> b >> c;

			graph[a].push_back(MP(b, c));
			graph[b].push_back(MP(a, c));

			d[a] = d[b] = INF;
		}

		dijkstra(dest);

		if (d[org] == INF) cout << "impossivel" << endl;
		else cout << d[org] << endl;

		graph.clear();
		d.clear();
	}
	
	return 0;
}