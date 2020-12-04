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

vector <int> graph[101];
vector <int> visited(101, 0);

void dfs(int v){
	visited[v] = 1;
	for (int i = 0; i < graph[v].size(); i++)
		if (!visited[graph[v][i]])
			dfs(graph[v][i]);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector <pair<int, int>> arr;
	for (int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		arr.push_back({x, y});
	}
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (arr[i].first == arr[j].first || arr[i].second == arr[j].second)
				graph[i].push_back(j), graph[j].push_back(i);

	int ans = 0;

	for (int i = 0; i < n; i++){
		if (!visited[i]){
			ans++; dfs(i);
		}
	}

	cout << ans-1 << endl;

	return 0;
}