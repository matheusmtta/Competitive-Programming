#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b; cin >> a >> b;
	int n = a.size();
	int m = b.size();

	int memo[n+1][m+1];

	//empty strings base case
	for (int i = 0; i <= n; i++)
		memo[i][0] = i;
	for (int j = 0; j <= m; j++)
		memo[0][j] = j;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i] == a[j])
				memo[i][j] = memo[i-1][j-1];
			else
				memo[i][j] = 1 + min({memo[i][j-1],    //Insert
									  memo[i-1][j],    //Delete
									  memo[i-1][j-1] })//Replace
		}
	}

	cout << memo[n][m] << endl;

	return 0;
}