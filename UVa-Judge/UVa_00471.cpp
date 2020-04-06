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

bool allow(int64 k){
	int r = k%10;
	int disc[10] = {0};

	while (k != 0){
		if (disc[r]) return false;
		disc[r] = 1;
		k /= 10;
		r = k%10;
	}
	return true;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){

		int64 n; cin >> n;

		int i = 1;

		while ((int)log10(i*n)+1 <= 10){
			if (allow(i) && allow(i*n))
				cout << i*n << " / " << i << " = " << n << endl;
			i++; 
		}

		if (t) cout << endl;
	}

	return 0;
}