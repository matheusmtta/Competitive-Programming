#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

#define MAXID 100
#define MAXW 300

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, limit;
vector <int> wgt, val;

int bottomUp1D (){
	int memo[MAXW];

	memset(memo, 0, sizeof memo);
	//1D array to store memoization data
	for (int i = 0; i < n; i++){
		for (int j = limit; j >= wgt[i]; j--){
			memo[j] = max(memo[j], memo[j - wgt[i]] + val[i]);
		}
	}

	return memo[limit];
}

int bottomUp2D (){
	int memo[MAXID][MAXW];

	memset(memo, 0, sizeof memo);

	//2D array to store memoization data
	for (int i = 0; i <= limit; i++)
		memo[0][i] = i - wgt[0] >= 0 ? val[0] : 0;

	for (int i = 1; i < n; i++){
		for (int j = 0; j <= limit; j++){
			int take = j - wgt[i] >= 0 ? val[i] + memo[i-1][j - wgt[i]] : -INF;
			int skip = memo[i-1][j];
			memo[i][j] = max(take, skip);
		}
	}

	return memo[n-1][limit];
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> limit;

	wgt.resize(n); val.resize(n);

	for (int i = 0; i < n; i++)
		cin >> val[i] >> wgt[i];

	int ans = bottomUp2D();
	int ans = bottomUp1D();

	return 0;
}