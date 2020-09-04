#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int memo[101][101][5][21][21];
bool calc[101][101][5][21][21];
int mtx[101][101];
int n, m, x, y;

int ans = INF;

int dp(int i, int j, int k, int a, int b){
	if (i == n-1 && j == m-1){
		if (mtx[i][j] == 0 && a > 0)
			return mtx[i][j];
		if (mtx[i][j] < 0 && b > 0)
			return mtx[i][j];
		if (mtx[i][j] > 0)
			return mtx[i][j];
		return INF;
	}

	int &curr = memo[i][j][k][a][b];

	if (calc[i][j][k][a][b])
		return curr;

	curr = INF;
	calc[i][j][k][a][b] = true;

	if (i+1 < n){
		if (mtx[i][j] == 0 && a > 0)
			curr = min(mtx[i][j] + dp(i+1, j, 2, a-1, b), curr);
		if (mtx[i][j] <  0 && b > 0)
			curr = min(mtx[i][j] + dp(i+1, j, 2, a, b-1), curr);
		if (mtx[i][j] >  0)
			curr = min(mtx[i][j] + dp(i+1, j, 2, a, b), curr);
	}
	if (j+1 < m && k != 1){
		if (mtx[i][j] == 0 && a > 0)
			curr = min(mtx[i][j] + dp(i, j+1, 0, a-1, b), curr);
		if (mtx[i][j] <  0 && b > 0)
			curr = min(mtx[i][j] + dp(i, j+1, 0, a, b-1), curr);
		if (mtx[i][j] >  0)
			curr = min(mtx[i][j] + dp(i, j+1, 0, a, b), curr);
	}
	if (j-1 >= 0 && k != 0){
		if (mtx[i][j] == 0 && a > 0)
			curr = min(mtx[i][j] + dp(i, j-1, 1, a-1, b), curr);
		if (mtx[i][j] <  0 && b > 0)
			curr = min(mtx[i][j] + dp(i, j-1, 1, a, b-1), curr);
		if (mtx[i][j] >  0)
			curr = min(mtx[i][j] + dp(i, j-1, 1, a, b), curr);
	}

	return curr;
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> m >> x >> y){
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> mtx[i][j];

		memset(calc, false, sizeof calc);

		int ans = dp(0, 0, 0, x, y);

		if (ans < 1000100)
			cout << ans << endl;
		else
			cout << "Impossivel" << endl;
	}

	return 0;
}