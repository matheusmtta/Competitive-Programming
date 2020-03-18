 
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

vector <int> graph[1100];
vector <int> visited(1100, 0);
int n, m;	
bool A, B;
int q = 0;
map <int, char> mp;

void DFS(int s){
	visited[s] = 1;
	if (mp[s] == 'B') q++;

	for (int i = 0; i < graph[s].size(); i++){
		if (!visited[graph[s][i]])
			DFS(graph[s][i]);
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> m){
		for (int i = 1; i <= n; i++){
			char x; cin >> x;
			mp[i] = x;
		}

		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		bool ans = true;

		for (int i = 1; i <= n; i++){
			q = 0;
			if (!visited[i]){
				DFS(i);
			}
			if (q%2==1) ans = false;
		}

		ans ? cout << "Y" << endl : cout << "N" << endl;

		for (int i = 0; i < 1100; i++){
			visited[i] = 0;
			graph[i].clear();
		}
		mp.clear();
	}

	return 0;
}