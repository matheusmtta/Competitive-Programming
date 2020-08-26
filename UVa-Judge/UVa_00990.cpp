#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, limit, w;
int memo[50][10000];
vector <int> v, cost;
vector <int> r;

int dp(int idx, int C){
	if (C > limit) return -INF;
	if (idx == n) return 0;

	int &curr = memo[idx][C];

	if (memo[idx][C] != -1)
		return memo[idx][C];

	curr = max(dp(idx+1, C), v[idx] + dp(idx+1, C+cost[idx]));

	return curr;
}

void recover(int idx, int C){
	if (idx == n) return;

	int pick = v[idx] + dp(idx+1, C+cost[idx]);
	int left = dp(idx+1, C);

	if (pick >= left){
		r.push_back(idx);
		recover(idx+1, C+cost[idx]);
	}
	else {
		recover(idx+1, C);	
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool flag = false;

	while(cin >> limit >> w){
		cin >> n;
		if (flag) cout << endl;

		flag = true;

		memset(memo, -1, sizeof memo);

		for (int i = 0; i < n; i++){
			int x, y; cin >> x >> y;
			cost.push_back(3*w*x);
			v.push_back(y);
		}

		cout << dp(0, 0) << endl;
		
		recover(0, 0);

		cout << r.size() << endl;

		for (int i = 0; i < r.size(); i++)
			cout << cost[r[i]]/(3*w) << " " << v[r[i]] << endl;

		r.clear(); v.clear(); cost.clear();
	}

	return 0;
}