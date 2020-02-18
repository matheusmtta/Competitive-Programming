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
		int n, m; cin >> n >> m;

		int p = 2 << (n-1);

		bitset <1025> a, b;

		for (int i = 1; i <= p; i++)
			a.set(i);

		for (int i = 0; i < m; i++){
			int x; cin >> x;
			a.reset(x);
		}

		int wo = 0;

		for (int i = 1; i <= n; i++){
			int k = 1;
			for (int j = 1; j <= p/(1 << (i-1)); j+=2){
				wo += (a[j]^a[j+1]);
				int nx = (a[j] | a[j+1]);
				a[k] = nx;
				k++;
			}
		}

		cout << wo << endl;
	}


	return 0;
}