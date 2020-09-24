#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, m;
int memo[20010];

int dp(int num){
	if (num <= 0)
		return INF;
	if (num == m)
		return 0;

	int &curr = memo[num];

	if (memo[num] != -1)
		return memo[num];

	memo[num] = INF;

	if (num < m)
		curr = 1 + dp(2*num);
	curr = min(curr, 1+dp(num-1));

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	memset(memo, -1, sizeof memo);
	cout << dp(n) << endl;

	return 0;
}