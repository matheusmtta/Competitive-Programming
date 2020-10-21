#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int mtx[11][1100];
int memo[11][1100];
int x;

int dp(int i, int j){
	if (j == x && i == 0){
		return 0;
	}
	if (j == x)
		return INF;

	int &curr = memo[i][j];

	if (curr != -1)
		return curr;

	curr = INF;

	if (i != 0)
		curr = min(curr, dp(i-1, j+1)+20-mtx[i][j]);
	if (i != 9)
		curr = min(curr, dp(i+1, j+1)+60-mtx[i][j]);
	
	curr = min(curr, dp(i, j+1)+30-mtx[i][j]);

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n; cin >> n; x = n/100;

		for (int i = 9; i >= 0; i--)
			for (int j = 0; j < x; j++)
				cin >> mtx[i][j];

		memset(memo, -1, sizeof memo);

		cout << dp(0, 0) << endl;

		cout << endl;
	}
	
	return 0;
}