 
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int64 mx;

int64 binary_search(int64 nd, int64 b){
	int l = 2*nd, r = 2*nd+1;
	if (l < mx && r < mx){
		if (b%2 == 0)
			binary_search(r, b/2);
		else
			binary_search(l, b/2+1);	
	}
	else return nd;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64 t; cin >> t;

	while (true){
		int64 n, k; cin >> n;
		if (n == -1) break;
		cin >> k;
		mx = pow(2, n);
		cout << binary_search(1, k) << endl;
	}

	return 0;
}