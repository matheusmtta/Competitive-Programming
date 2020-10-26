#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, m;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> m){
		if (n == 0 && m == 0)
			return 0;
		vector <int> arr(n);
		for (int &x : arr)
			cin >> x;
		
		vector <vector<int64>> memo(n+10, vector<int64>(n+10, 0));

		memo[0][0] = 1;
		for (int i = 1; i <= n; i++)
			memo[i][0] = 1;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				memo[i][j] = ((memo[i-1][j-1]*arr[i-1])%m + (memo[i-1][j]%m))%m;

		int64 ans = 0;

		for (int i = 1; i <= n; i++)
			ans = max(ans, memo[n][i]);

		cout << ans << endl;
	}

	return 0;
}
