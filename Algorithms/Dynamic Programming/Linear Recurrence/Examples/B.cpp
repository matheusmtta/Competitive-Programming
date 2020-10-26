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

int64 dim = 2;

matrix multiply(matrix A, matrix B){
	matrix ans(2, vector<int64>(dim, 0));

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			for (int k = 0; k < dim; k++)
				ans[i][j] = (ans[i][j] + A[i][k]*B[k][j])%MOD;

	return ans;
}

matrix matrixExp(matrix mtx, int64 exp){
	if (exp == 1)
		return mtx;
	if (exp%2 == 1)
		return multiply(mtx, matrixExp(mtx, exp-1));
	
	matrix res = matrixExp(mtx, exp/2);

	return multiply(res, res);
}

int main(){	
	int64 n; cin >> n;
	
	matrix mtx(2, vector<int64>(dim, 0));

	mtx[0][0] = 19;
	mtx[0][1] = 7;
	mtx[1][0] = 6;
	mtx[1][1] = 20;

	matrix ans = matrixExp(mtx, n);

	cout << ans[0][0] << endl;

	return 0;
}