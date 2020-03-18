 
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF 1000000000000
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 100000;

int n, m;
vector <int> graph[MAX];
vector <int> visited(MAX, 0);

void dfs(int s){
	visited[s] = 1;

	for (int i = 0; i < graph[s].size(); i++){
		if (!visited[graph[s][i]])
			dfs(graph[s][i]);
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q = 1;

	while (true){
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		for (int i = 0; i < m; i++){
			int x; cin >> x;
			int y; cin >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		int ans = 0;

		for (int i = 1; i <= n; i++){
			if (!visited[i]){
				ans++;
				dfs(i);
			}
		}

		if (ans == 1){
			cout << "Teste " << q << endl;
			cout << "normal" << endl;
		}
		else{
			cout << "Teste " << q << endl;
			cout << "falha" << endl;
		}

		for (int i = 0; i < MAX; i++){
			graph[i].clear();
			visited[i] = 0;
		}
		q++;
		cout << endl;
	}

	return 0;
}