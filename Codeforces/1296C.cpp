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
		string str; cin >> str;

		int mn = INF;

		map <pair <int, int>, int> mp;
		pair <int, int> pos = MP(0, 0);

		mp[pos] = 0;

		int l = -1, r = -1;

		for (int i = 0; i < str.length(); i++){
			if (str[i] == 'L') pos.first--;
			else if (str[i] == 'R') pos.first++;
			else if (str[i] == 'U') pos.second++;
			else if (str[i] == 'D') pos.second--;

			if (mp.find(pos) != mp.end()){
				int x1, y1;
				x1 = mp[pos]+1;
				y1 = i+1;
				if (y1 - x1 + 1 < mn){
					l = x1;
					r = y1;
					mn = r - l + 1;
				}
			}
			mp[pos] = i+1;
		} 


		if (l != -1 && r != -1) cout << l << " " << r << endl;
		else cout << -1 << endl;
	}

	return 0;
}