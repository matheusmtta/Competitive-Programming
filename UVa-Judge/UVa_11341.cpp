#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9
#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int memo[50][200];
int c, limit;
int mtx[50][200];

int dp(int idx, int cap){
	if (idx == c)
		return 0;
	
	int &curr = memo[idx][cap];

	if (curr != -1)
		return curr;

	curr = -INF;

	for (int i = 1; i <= cap; i++){
		if (mtx[idx][i-1] >= 5)
			curr = max(mtx[idx][i-1] + dp(idx+1, cap-i), curr);
	}

	return curr;
}

int main(){	
	int t; cin >> t;

	while (t--){
		cin >> c >> limit;
		
		memset(mtx, 0, sizeof mtx);

		for (int i = 0; i < c; i++){
			for (int j = 0; j < limit; j++){
				cin >> mtx[i][j];
			}
		}

		memset(memo, -1, sizeof memo);

		int ans = dp(0, limit);

		if (ans >= 0)
			printf("Maximal possible average mark - %.2lf.\n", (ans + 1e-12) / c);
		else
			printf("Peter, you shouldn't have played billiard that much.\n");
	}

	return 0;
}