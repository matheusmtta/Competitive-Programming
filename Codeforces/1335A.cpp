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
		int64 n; cin >> n;

		if (n == 1 || n == 2) {cout << 0 << endl; continue;}
		else {
			if (n%2==1) cout << (n/2) << endl;
			else cout << (n/2)-1 << endl;
		}
	}

	return 0;
}