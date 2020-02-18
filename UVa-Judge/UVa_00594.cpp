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

	int n;

	while (cin >> n){
		int ans = 0;

		for (int i = 0; i < 4; i++){
			ans = (ans << 8) | ((n >> (8*i) & 255));
		}

		cout << n << " converts to " << ans << endl;
	}

	return 0;
}