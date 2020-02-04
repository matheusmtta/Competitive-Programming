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
		int s; cin >> s;

		int aux = s;

		int32 ans = 0;

		while (1){
			if (s/10 <= 0) break;
			aux = s/10;
			s %= 10;
			s += aux;
			ans += 10*(aux);
		}
		
		cout << ans+s << endl;
	}

	return 0;
}