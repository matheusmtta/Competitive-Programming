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

	for (int i = n-1; i >= 0; i--){
		for (int j = m-1; j >= 0; j--){
			if (a[i] == b[j])
				memo[i][j] = 1 + memo[i+1][j+1];
			else memo[i][j] = max({memo[i+1][j], memo[i][j+1], memo[i][j]});
		}
	}

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