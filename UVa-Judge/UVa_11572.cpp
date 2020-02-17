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
		map <int, int> mp;

		int mx = 0, ans = 0, sz = 0;

		for (int i = 1; i <= n; i++){
			int tmp; cin >> tmp;

			if (mp.find(tmp) != mp.end()){
				sz = max(sz, mp[tmp]);
				mx = i - sz - 1;
			}

			mx++;
			mp[tmp] = i;
			ans = max(mx, ans);
		}

		cout << ans << endl;
	}

	return 0;
}