#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int ll;
typedef unsigned long long int  ull;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q = 1;
	while (cin >> n >> m){
		if (n == 0 && m == 0)
			exit(0);
		vector <int> a(n), b(m);

		for (int &x : a)
			cin >> x;

		for (int &x : b)
			cin >> x;

		int memo[n+1][m+1];
		memset(memo, 0, sizeof memo);

		for (int i = n-1; i >= 0; i--){
			for (int j = m-1; j >= 0; j--){
				if (a[i] == b[j])
					memo[i][j] = 1 + memo[i+1][j+1];
				else memo[i][j] = max({memo[i+1][j], memo[i][j+1], memo[i][j]});
			}
		}

		cout << "Twin Towers #" << q++ << endl;
		cout << "Number of Tiles : " << memo[0][0] << endl;
		cout << endl;
	}

	return 0;
}