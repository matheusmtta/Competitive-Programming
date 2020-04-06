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

	int q = 1;

	while (t--){
		int n, k; cin >> n >> k;
		map <char, int> mp;
		string str; cin >> str;

		cout << "Case " << q << ": ";

		int ans = 0;

		for (int i = 0; i < n; i++){
			if (mp.find(str[i]) == mp.end())
				mp[str[i]] = i;
			else {
				int aux = i - mp[str[i]];
				if (aux <= k) ans++;
				mp[str[i]] = i;
			}
		}

		cout << ans << endl;
		q++;
	}

	return 0;
}