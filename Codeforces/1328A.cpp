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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int64 a, b; cin >> a >> b;
		if (a%b == 0) {cout << 0 << endl; continue;}
		else {
			int64 ans = 0;
			if (b > a) {cout << b-a << endl; continue;}
			if (a%b != 0){
				int64 aux = a/b;
				aux += 1;
				aux *= b;
				ans = aux-a;
			}
			cout << ans << endl;
		}
	}

	return 0;
}