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
		int n; cin >> n;

		int s = -1, f = -1;

		bool ans = true;
		int lst1, lst2;

		for (int i = 0; i < n; i++){
			int x, y; cin >> x >> y;
			if (y < s || x < f) {ans = false;}
			if (i != 0 && (y-lst2) > (x-lst1)) {ans = false;}
			if (y > x) {ans = false;}
			lst1 = x;
			lst2 = y;
			s = max(s, y);
			f = max(x, f);
		}

		ans ? cout << "YES" << endl : cout << "NO" << endl;
	}	

	return 0;
}