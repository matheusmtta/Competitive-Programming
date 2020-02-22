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

vector <int> graph[1000005];

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	int n, m;

	while (cin >> n >> m){
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			int p = i;
			graph[x].push_back(p+1);
		}

		int v, k;

		for (int i = 0; i < m; i++){
			cin >> k >> v;

			if (k > graph[v].size()) cout << 0 << endl;
			else cout << graph[v][k-1] << endl;
		}

		for (int i = 0; i < 1000005; i++)
			graph[i].clear();	
	}
	
	return 0;
}