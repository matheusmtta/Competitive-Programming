#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;					

vector <int> val, wgt;
int memo[100][100100];
int m, n;

int dp(int idx, int cost){
	if (cost > m && m < 1800)
		return -INF;
	if (cost > m + 200)
		return -INF;
;	if (idx == n) {
		if (cost > m && cost <= 2000)
			return -INF;
		return 0;
	}

	int &curr = memo[idx][cost];

	if (curr != -1)
		return curr;

	curr = max(dp(idx+1, cost), val[idx] + dp(idx+1, cost+wgt[idx]));

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> m >> n){
		val.resize(n); wgt.resize(n);

		for (int i = 0; i < n; i++){
			cin >> wgt[i];
			cin >> val[i];
		}


		memset(memo, -1, sizeof memo);

		cout << dp(0, 0) << endl;
	}

	return 0;
}