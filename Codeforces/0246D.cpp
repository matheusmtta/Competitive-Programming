#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	
	vector <vector <int>> graph(n+1);

	map <int, set<int>> mp;

	int id = 1;

	vector <pair<int,int>> color = {{-1, -1}};
	for (int i = 0; i < n; i++){
		int c; cin >> c;
		mp[c] = {0};
		color.push_back({i+1, c});
	}

	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	vector <int> visited(n+1, 0);
	queue <int> q;

	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			q.push(i);
			visited[i] = 1;
			while (!q.empty()){
				int v = q.front();
				q.pop();

				for (int u : graph[v]){
					if (color[v].second != color[u].second)
						mp[color[v].second].insert(color[u].second);
					if (!visited[u]){
						visited[u] = 1;
						q.push(u);
					}
				}
			}
		}
	};

	int mx = -INF, ans =  -1;

	for (auto x : mp){
		if ((int)x.second.size() > mx){
			mx = x.second.size();
			ans = x.first;
		}
	}

	cout << ans << endl;

	return 0;
}