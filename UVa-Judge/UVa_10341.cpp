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

int p, q, r, s, t, u;

double solve(double x){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main(){	
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	while (cin >> p >> q >> r >> s >> t >> u){
		if (solve(0)*solve(1) > 0)
			cout << "No solution" << endl;
		else {
			double ans;

			double l = 0, r = 1;

			while (l + 1e-7 <= r){
				double x = (l+r)/2;
				if (solve(l)*solve(x) <= 0)
					r = x;
				else
					l = x;
			}

			ans = (l+r)/2;

			printf("%.4lf\n", ans);
		}
	}

	return 0;
}