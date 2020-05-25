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

int64 A, B;

int64 get_val(int64 x){
	int64 ans = 0;
	if (x > 1000000){
		ans += 7*(x - 1000000);
		x = 1000000;
	}
	if (x > 10000){
		ans += 5*(x - 10000);
		x = 10000;
	}
	if (x > 100){
		ans += 3*(x - 100);
		x = 100;
	}
	if (x > 0)
		ans += 2*x;
	return ans;
}

int64 solve(int64 x){
	int64 l = 1, r = 1000000000;

	while (l <= r){
		int64 mid = (l+r)/2;
		int64 rsp = get_val(mid);
		if (rsp == x)
			return mid;
		if (rsp > x) r = mid - 1;
		else if (rsp < x) l = mid + 1;
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> A >> B){
		if (A == 0 && B == 0) return 0;

		int64 tot = solve(A);

		int64 l = 0;
		int64 r = tot;

		while (l <= r){
			int64 mid = (l+r)/2;
			int64 x = get_val(mid);
			int64 y = get_val(tot-mid);

			if (abs(x-y) == B) {
				cout << min(x, y) << endl;
				break;
			}
			if (x > y || y-x < B) r = mid - 1;
			else l = mid + 1;
		}
	}

	return 0;
}