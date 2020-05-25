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

	int t; 

	while (cin >> t){
		if (t == 0) return 0;
		vector <double> arr; 

		for (int i = 0; i < t+1; i++){
			double x; cin >> x;
			arr.push_back(x);
		}

		double l = -1, r = 10000, mid, it = 0;

		while (l <= r && it < 100){
			mid = (l+r)/2;
			it++;
			double ans = arr[0];
			for (int i = 1; i < t+1; i++){
				ans += arr[i]/pow(1 + mid, i);
			}
			if (ans > 0)
				l = mid;
			else
				r = mid;
		}
		printf("%.2lf\n", mid);
	}	

	return 0;
}