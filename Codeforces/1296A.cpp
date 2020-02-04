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
		int n; cin >> n;
		vector <int> arr(n);

		int odds = 0, even = 0, sum = 0;

		for (int i = 0; i < n; i++){
			cin >> arr[i];
			sum += arr[i];
			if (arr[i]%2 == 0) even++;
			else odds++;
		}

		if (sum%2 == 1) {cout << "YES" << endl; continue;}
		if (odds > 0 && even > 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}