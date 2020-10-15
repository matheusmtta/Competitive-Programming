#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

typedef vector<vector<int64>> matrix;

int64 dim = 2;

matrix multiply(matrix A, matrix B){
	matrix ans(dim, vector<int64>(dim, 0));

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			for (int k = 0; k < dim; k++)
				ans[i][j] = (ans[i][j]%MOD + A[i][k]*B[k][j]%MOD)%MOD;

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

	int64 exp, l, k;
	while (cin >> exp >> k >> l){
		exp /= 5;

		matrix mtx(dim, vector<int64>(dim, 0));

		mtx[0][0] = 0;
		mtx[0][1] = l%MOD;
		mtx[1][0] = 1;
		mtx[1][1] = k%MOD;

		matrix ans = matrixExp(mtx, exp);
		
		int64 rsp = ans[1][1];

		if (rsp == 0)
			cout << "000000" << endl;
		else {
			for (int i = 0; i < 6 - (int)log10(rsp)-1; i++)
				cout << 0;

			cout << rsp << endl;
		}
	}


	return 0;
}
