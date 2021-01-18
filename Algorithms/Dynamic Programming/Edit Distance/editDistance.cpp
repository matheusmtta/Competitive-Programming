#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int memo[1000][1000];

void recover(string &a, string &b){
	int i = (int)a.size(), j = (int)b.size(), op = 1;

	while (i && j){
		if (a[i-1] == b[j-1])
			j--, i--;
		else if (memo[i][j] == memo[i-1][j-1] + 1){
			cout << op++ << " Replace " << i << ", " << b[j-1] << endl;
			i--, j--;
		}
		else if (memo[i][j] == memo[i-1][j] + 1){
			cout << op++ << " Delete " << i << endl;
			i--;
		}
		else if (memo[i][j] == memo[i][j-1] + 1){
			cout << op++ << " Insert " << i << ", " << b[j-1] << endl;
			j--;
		}
	}

	while (i > 0){
		cout << op++ << " Delete " << i << endl;
		i--;
	}

	while (j > 0){
		cout << op++ << " Insert " << j << ", " << b[j-1] << endl;
		j--;
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b; cin >> a >> b;
	
	int n = (int)a.size(), m = (int)b.size();
	memset(memo, 0, sizeof memo);

	for (int i = 0; i <= n; i++)
		memo[i][0] = i;
	for (int j = 0; j <= m; j++)
		memo[0][j] = j;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i-1] == b[j-1])
				memo[i][j] = memo[i-1][j-1];
			else {
				int insert = memo[i][j-1];
				int remove = memo[i-1][j];
				int replace = memo[i-1][j-1];

				memo[i][j] = 1 + min({insert, remove, replace});
			}
		}
	}

	cout << memo[n][m] << endl;
	recover(a, b);
	
	return 0;
}