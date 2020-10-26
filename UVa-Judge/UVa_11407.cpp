#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	vector <int> memo(10100, INF);

	memo[1] = 1; 
	memo[0] = 0;

	for (int i = 2; i <= 10000; i++)
		for (int j = (int)sqrt(i); j > 0; j--)
			memo[i] = min(memo[i], memo[i - (j*j)] + 1);

	while (t--){
		int n; cin >> n;
		cout << memo[n] << endl;
	}

	return 0;
}
