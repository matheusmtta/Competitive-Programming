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

int64 dim;

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

int main(){	
	int64 exp, m; cin >> dim >> m >> exp;

	matrix mtx(dim, vector<int64>(dim, 0));

	for (int i = 0; i < m; i++){
		int x, y; 
		cin >> x >> y;
		x--; y--;
		mtx[x][y] = 1;
	}

	matrix ans = matrixExp(mtx, exp);

	int64 rsp = 0;

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			rsp = (rsp + ans[i][j])%MOD;

	cout << rsp << endl;

	return 0;
}