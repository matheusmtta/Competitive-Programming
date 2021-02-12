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

	int n, m;
	vector <int> a(n), b(m);

	for (int &x : a)
		cin >> x;

	for (int &x : b)
		cin >> x;

	int memo[n+1][m+1];
	memset(memo, 0, sizeof memo);

	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			if (i == 0 || j == 0) memo[i][j] = 0;
			else if (s[i-1] == t[j-1])
				memo[i][j] = memo[i-1][j-1] + 1;
			else
				memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
		}
	}

	//recover answer
	// string ans;
	// int i = n, j = m;
	// while (i > 0 && j > 0){
	// 	if (s[i-1] == t[j-1])
	// 		ans += s[i-1], i--, j--;
	// 	else if (memo[i-1][j] > memo[i][j-1])
	// 		i--;
	// 	else
	// 		j--;
	// }
	//reverse(ans.begin(), ans.end());
	//cout << ans << endl;
	////////////////////////////////////////////
	//O(m) auxiliar memory
	// vector <int> m1(m+1, 0), m2(m+1, 0);
	
	// for (int i = n-1; i >= 0; i--){
	// 	for (int j = m-1; j >= 0; j--){
	// 		if (a[i] == b[j])
	// 			m1[j] = 1 + m2[j+1];
	// 		else
	// 			m1[j] = max(m1[j+1], m2[j]);
	// 	}
	// 	m2 = m1;
	// }

	// cout << m1[0] << endl;

	cout << memo[0][0] << endl;

	return 0;
}