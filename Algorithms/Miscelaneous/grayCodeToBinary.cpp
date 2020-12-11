#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

//graycode to binary
int inv(int n){
	int rsp = 0;
	while (n){
		rsp ^= n;
		n >>= 1;
	}
	return rsp;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n, k;
		cin >> n >> k;

		//binary to graycode
		int ans = k^(k >> 1);
		int ans = inv(k);
	}

	return 0;
}