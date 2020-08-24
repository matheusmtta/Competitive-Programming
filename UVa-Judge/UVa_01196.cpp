#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while (cin >> n){
		if (n == 0) break;
		map <pair<int, int>, int> mp;
		vector <vector <int>> memo(110, vector<int>(110, 0));

		for (int i = 0; i < n; i++){
			int l, m; cin >> l >> m;
			mp[{l, m}]++;
		}

		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++)
				memo[i][j] = max(memo[i-1][j], memo[i][j-1]) + mp[{i,j}];

		cout << memo[100][100] << endl;
	}
	cout << "*" << endl;

	return 0;
}