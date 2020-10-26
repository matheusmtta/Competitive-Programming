#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MAX 201

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, k;
int64 C[MAX][MAX];

void build(){
	C[0][0] = 1;

	for (int i = 1; i <= MAX; i++){
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < MAX; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%MOD;
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	build();

	while (cin >> n >> k) { 
		if (n == 0 && k == 0)
			return 0;
		cout << C[n + k - 1][k - 1] << endl;
	}

	return 0;
}
