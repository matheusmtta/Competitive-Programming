#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define end "\n"
#define first f
#define second s
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;

	int ans = 0;

	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			if ((i*i + j == n && i + j*j == m) || (j*j + i == n && j + i*i == m))
				ans++;

	n == m ? cout << ans << endl : cout << ans/2 << endl;

	return 0;
}
