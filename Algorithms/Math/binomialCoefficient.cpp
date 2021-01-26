#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int64 modMul(int64 a, int64 b){
	return (a*b)%MOD;
}

int64 fastExp(int64 a, int64 b){
	if (b == 0) return 1;

	int64 tmp = fastExp(a, b/2);
	int64 ans = modMul(tmp, tmp);

	if (b & 1)
		return modMul(ans, a);

	return ans;
}

int64 modInv(int64 a){
	return fastExp(a, MOD-2);
}

int64 binom(int64 n, int64 k, vector <int64> &fac){
	return modMul(fac[n], modMul(modInv(fac[n-k]), modInv(fac[k])));
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	
	vector <int64> fac(n+1, 0);
	fac[0] = 1;

	for (int i = 1; i <= n; i++)
		fac[i] = modMul(fac[i-1], i);

	cout << binom(n, k, fac) << endl;

	return 0;
}