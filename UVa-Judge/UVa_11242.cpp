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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int f, r;

	while (cin >> f){
		if (f == 0) exit(0);
		cin >> r;
		vector <double> fv, rv;

		for (int i = 0; i < f; i++){
			double x; cin >> x;
			fv.push_back(x);
		}

		for (int i = 0; i < r; i++){
			double x; cin >> x;
			rv.push_back(x);
		}

		vector <double> a;

		for (int i = 0; i < r; i++)
			for (int j = 0; j < f; j++)
				a.push_back(rv[i]/fv[j]);

		sort(a.begin(), a.end());

		double ans = -1;

		for (int i = 1; i < a.size(); i++){
			ans = max(a[i]/a[i-1], ans);
		}

		printf("%.2lf\n", ans);
	}

	return 0;
}