#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MAX 100

typedef long long int int64;
typedef unsigned long long int  uint64;

//Computes the pascal triangle in O(n^2)

int n, k;
int64 C[MAX][MAX];

void build(){
	C[0][0] = 1;

	for (int i = 1; i <= n; i++)
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j <= n; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%MOD;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	build();

	return 0;
}
