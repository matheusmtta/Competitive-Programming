#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int n;
int memo[1100][6200];
vector <pair<int, int>> arr;

int dp(int idx, int limit){
	if (idx == n || limit < 0)
		return 0;

	int &curr = memo[idx][limit];

	if (curr != -1)
		return curr;

	if (arr[idx].first <= limit)
		curr = max(dp(idx+1, limit),
				   1 + dp(idx+1, min(arr[idx].second, limit - arr[idx].first)));
	else curr = dp(idx+1, limit);

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	while (cin >> n){
		if (n == 0)
			exit(0);

		for (int i = 0; i < n; i++){
			int x, y; cin >> x >> y;
			arr.push_back({x, y});
		}
		
		int ans = -1;
		
		memset(memo, -1, sizeof memo);

		ans = dp(0, 6200);

		cout << ans << endl;

		arr.clear();
	}

	return 0;
}