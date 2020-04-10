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

		int64 a[n], b[n];

		int64 ans = 0;

		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i];

		for (int i = 0; i < n; i++){
			if (b[i] < a[(i+1)%n]){
				ans += a[(i+1)%n] - b[i];
				a[(i+1)%n] = b[i];
			}
		}

		ans += *min_element(a, a+n);

		cout << ans << endl;
	}

	return 0;
}