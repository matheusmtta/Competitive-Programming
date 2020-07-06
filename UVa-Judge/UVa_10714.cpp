#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int sz, n; cin >> sz >> n;
		vector <int> arr;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back(x);
		}
		sort(arr.begin(), arr.end());
		int mn = -1, mx = -1;
		for (int i = 0; i < n; i++){
			mn = max(mn, min(arr[i], (sz-arr[i])));
			mx = max(mx, max(arr[i], (sz-arr[i])));
		}

		cout << mn << " " << mx << endl;
	}

	return 0;
}