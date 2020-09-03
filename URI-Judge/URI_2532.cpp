#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, p; 
int memo[1100][2100];
vector <int> m, v;

int dp(int idx, int hp){
	if (idx == n && hp > 0)
		return INF;
	if (hp <= 0)
		return 0;

	int &curr = memo[idx][hp];

	if (curr != -1)
		return curr;

	curr = min(dp(idx+1, hp), m[idx]+dp(idx+1, hp - v[idx]));

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> p){
		m.resize(n); v.resize(n);

		for (int i = 0; i < n; i++)
			cin >> v[i] >> m[i];
	
		memset(memo, -1, sizeof memo);

		int ans = dp(0, p);

		ans == INF ? cout << -1 << endl : cout << ans << endl;
	}

	return 0;
}