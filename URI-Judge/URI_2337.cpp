#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

typedef vector<vector<int64>> matrix;

int dim = 2;

matrix multiply(matrix A, matrix B){
	matrix ans(dim, vector<int64>(dim, 0));

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			for (int k = 0; k < dim; k++)
				ans[i][j] = (ans[i][j] + A[i][k]*B[k][j])%MOD;

	return ans;
}

matrix matrixExp(matrix mtx, int64 exp){
	matrix ans(dim, vector<int64>(dim, 0));

	for (int i = 0; i < dim; i++)
		ans[i][i] = 1;

	while (exp > 0){
		if (exp & 1){
			ans = multiply(ans, mtx);
		}
		exp = exp >> 1;
		mtx = multiply(mtx, mtx);
	}

	return ans;
}

int64 gcd (int64 a, int64 b){
	return b ? gcd(b, a % b) : a;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin >> n){
		matrix mtx(dim, vector<int64>(dim, 0));
	
		mtx[0][0] = 0;
		mtx[0][1] = 1;
		mtx[1][0] = 1;
		mtx[1][1] = 1;

		matrix ans = matrixExp(mtx, n+1);

		int64 ans1 = ans[1][1];
		int64 ans2 = 1LL << n;

		int64 div = gcd(ans1, ans2);

		cout << ans1/div << "/" << ans2/div << endl;
	}

	return 0;
}