#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> g[25];
int memo[30][210];
int m, c; 

int dp(int idx, int mo){
	if (mo < 0) return -INF;
	if (idx == c) return m - mo;

	int &curr = memo[idx][mo];

	if (curr != -1)
		return curr;

	curr = -INF;

	for (int i = 0; i < g[idx].size(); i++)
		curr = max(curr, dp(idx+1, mo - g[idx][i]));

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		cin >> m >> c;
		for (int i = 0; i < 25; i++)
			g[i].clear();
		//cout << endl;
		for (int i = 0; i < c; i++){
			int k; cin >> k;
			for (int j = 0; j < k; j++){
				int x; cin >> x;
				g[i].push_back(x);
			}
		}

		memset(memo, -1, sizeof memo);

		int ans = dp(0, m);

		if (ans > 0) cout << ans << endl;
		else cout << "no solution" << endl;

		for (auto x : g)
			x.clear();
	}

	return 0;
}