#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int l, s;
int memo[27][10010][27];

int dp(int i, int j, int k){
	if (j == s && i == l)
		return 1;
	if (j >= s || i >= l)
		return 0;

	int &curr = memo[i][j][k];

	if (curr != -1)
		return curr;

	curr = 0;

	for (int idx = k+1; idx <= 26; idx++)
		curr += dp(i+1, j+idx, idx);

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q = 1;
	while (cin >> l >> s) { 
		if (l == 0 && s == 0)
			return 0;
		memset(memo, -1, sizeof memo);
		cout << "Case " << q++ << ": ";
		cout << dp(0, 0, 0) << endl;
	}

	return 0;
}
