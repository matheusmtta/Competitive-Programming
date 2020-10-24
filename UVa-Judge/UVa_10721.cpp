#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, m, k;
int64 memo[200][200];

int64 dp(int sz, int b){
	if (b == k && sz == n)
		return 1;
	if (sz == n && b != k)
		return 0;
	if (sz > n || b > k)
		return 0;

	int64 &curr = memo[sz][b];

	if (curr != -1)
		return curr;

	curr = 0;

	for (int i = 1; i <= m; i++)
		curr += dp(sz + i, b+1);

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	while (cin >> n >> k >> m){
		memset(memo, -1, sizeof memo);
 	
		cout << dp(0, 0) << endl;
	}

	return 0;
}