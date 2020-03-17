#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
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
		if (n == 0 && m == 0) exit(0);
		map <int, int> mp;
		for (int i = 0; i < m; i++){
			int x; cin >> x;
			mp[x]++;
		}

		int ans = 0;

		for (auto i : mp){
			if (i.second > 1) ans++;
		}

		cout << ans << endl;
	}
	
	return 0;
}