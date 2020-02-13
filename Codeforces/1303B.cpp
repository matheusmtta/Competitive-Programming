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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int64 n, g, b; cin >> n >> g >> b;

		int64 gasp = ceil(n/2.0);
		int64 nasp = n - gasp;

		if (g >= gasp) {cout << gasp + nasp << endl; continue;}

		int64 aux = gasp/g;
		int64 r = gasp%g;
		int64 ans;

		if (r == 0){
			ans = aux*b + aux*g - b;
			if (n <= ans)
				cout << ans << endl;
			else
				cout << n << endl;
		}
		else {
			ans = aux*b + aux*g + r;
			if (n <= ans)
				cout << ans << endl;
			else
				cout << n << endl;
		}

	}

	return 0;
}