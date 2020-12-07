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

int ans = 0;
vector <int> g[2010];

void dfs(int v, int depth){
	ans = max(depth, ans);
	for (int i = 0; i < g[v].size(); i++)
		dfs(g[v][i], depth+1);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++){
		int x; cin >> x; x--;
		if (x >= 0) g[x].push_back(i); 
	}

	for (int i = 0; i < n; i++)
		dfs(i, 1);

	cout << ans << endl;

	return 0;
}