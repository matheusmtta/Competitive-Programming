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

int mtx[10][10];

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> mtx[i][j];

		int p[10];

		for (int i = 0; i < n; i++) p[i] = i;

		int ans = INF;

		do {
			int sum = 0;
			for (int i = 0; i < n; i++)
				sum += mtx[i][p[i]];
			ans = min(ans, sum);
		} while (next_permutation(p, p+n));

		cout << ans << endl;
	}

	return 0;
}