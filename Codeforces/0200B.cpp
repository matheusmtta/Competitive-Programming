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
	int n; cin >> n;
	double ans;

	for (int i = 0; i < n; i++){
		float x; cin >> x; ans += x; 
	}

	printf("%lf\n", ans/n);
}