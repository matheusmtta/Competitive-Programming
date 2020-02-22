 
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

vector <int> visited(26, 0);
vector <int> graph[26];

int DFS(int v){
	visited[v] = 1;
	for (int i = 0; i < graph[v].size(); i++){
		if (!visited[graph[v][i]]) DFS(graph[v][i]);
	}
	return 1;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		string str;
		while (true){
			cin >> str;
			if (str[0] != '(') break;
			int x = str[1] - 'A';
			int y = str[3] - 'A';

			graph[x].PB(y);
			graph[y].PB(x);
		}

		bool vertices[26];

		for (int i = 0; i < 26; i++) vertices[i] = 0;

		cin >> str;

		for (int i = 0; i < str.length(); i++){
			if (str[i] != ',') vertices[str[i]-'A'] = 1;
		}

		int ans = 0;

		for (int i = 0; i < 26; i++){
			if (!visited[i] && vertices[i])
				ans += DFS(i);
		}

		int ac = 0;

		for (int i = 0; i < 26; i++){
			if (vertices[i] && graph[i].size() == 0) ac++;
		}

		cout << "There are " << ans-ac << " tree(s) and " << ac << " acorn(s)." << endl;

		for (int i = 0; i < 26; i++){
			visited[i] = 0;
			graph[i].clear();
		}
	}

	return 0;
}