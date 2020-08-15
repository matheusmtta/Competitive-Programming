#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector <int> arr;
		map <int, int> mp;
		for (int i = 0; i < n; i++){
			char x; cin >> x;
			arr.push_back(x-'0'-1);
		}
		
		int64 curr = 0, ans = 0;

		for (int i = 0; i < n; i++){
			curr += arr[i];
			if (curr == 0)
				ans ++;
			if (mp.find(curr) != mp.end())
				ans += mp[curr];
			mp[curr]++;
		}
		cout << ans << endl;
	}

	return 0;
}