#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int64 dim = 2;

vector <vector<double>> multiply(vector <vector<double>> A,
				vector <vector<double>> B){
	vector <vector<double>> ans(2, vector<double>(2, 0));

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			for (int k = 0; k < dim; k++)
				ans[i][j] = ans[i][j] + (A[i][k]*B[k][j]);

	return ans;
}

vector <vector<double>> matrixExp(vector <vector<double>> mtx, int n){
	if (n == 1)
		return mtx;
	if (n%2 == 1)
		return multiply(mtx, matrixExp(mtx, n-1));
	
	vector <vector<double>> res = matrixExp(mtx, n/2);

	return multiply(res, res);
}

int main(){	
	int n; cin >> n;
	double p; cin >> p;

	vector <vector<double>> mtx(2, vector<double>(2, 0));

	mtx[0][0] = 1 - p;
	mtx[0][1] = p;
	mtx[1][0] = p;
	mtx[1][1] = 1 - p;

	vector <vector<double>> ans = matrixExp(mtx, n);

	printf("%.9lf\n", ans[0][0]);

	return 0;
}