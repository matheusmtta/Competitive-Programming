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

	while (true){
		int n, m; cin >> n >> m;
		int32 ans = 0;

		map <int, int> mp;

		if (n == 0 && m == 0) exit(0);

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			mp[x]++;
		}

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			mp[x]++;
		}

		for (auto i : mp){
			if (i.second == 2)
				ans++;
		}

		cout << ans << endl;
	}

	return 0;
}