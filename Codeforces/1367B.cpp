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
		int n; cin >> n;
		vector <int> arr;
		int ev = 0, odd = 0;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			if (x%2 == 0) ev++;
			else odd++;
			arr.push_back(x);
		}

		if (n%2 == 1 && ev - odd != 1){
			cout << -1 << endl;
			continue;
		}
		if (n%2 == 0 && ev != odd){
			cout << -1 << endl;
			continue;
		}

		ev = odd = 0;

		for (int i = 0; i < n; i++){
			if (arr[i]%2 != i%2){
				if (arr[i]%2 == 1) odd++;
				else ev++;
			}
		}

		cout << max(ev, odd) << endl;
	}

	return 0;
}