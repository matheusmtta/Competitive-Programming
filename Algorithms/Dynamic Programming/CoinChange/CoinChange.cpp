#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> basis = {1, 5, 10, 25, 50}; //coins available

int objective, n;

int64 dp_count(){
	vector <int64> memo(10000, 0);
	memo[0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = basis[i]; j < memo.size(); j++)
			memo[j] += memo[j - basis[i]];


	return memo[objective];
}

int dp_minimum(){
	vector <int64> memo(10000, 0);
	memo[0] = 0;

	for (int i = 1; i <= objective; i++){
		memo[i] = INF;
		for (int j = 0; j < n; j++){
			if (basis[j] <= i)
				memo[i] = min(memo[i], 1 + memo[i - basis[j]]);
		}
	}

	return memo[objective];
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> objective;

	n = basis.size();

	cout << "number of ways: " << dp_count() << endl;
	cout << "minimum number of coins needed: " << dp_minimum() << endl;

	return 0;
}