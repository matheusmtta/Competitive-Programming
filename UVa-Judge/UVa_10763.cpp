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

	int n;

	while (cin >> n){
		if (n == 0) return 0;
		vector <pair<int, int>> arr;
		map <pair<int, int>, int> mp;
		for (int i = 0; i < n; i++){
			int x, y; cin >> x >> y;
			arr.push_back({x, y});
			mp[{x, y}]++;
		}
		bool ans = true;
		for (int i = 0; i < n; i++){
			int x = arr[i].first;
			int y = arr[i].second;
			if (mp[{x, y}] != mp[{y, x}]) ans = false;
		}
		ans ? cout << "YES" << endl : cout << "NO" << endl;
	}

	return 0;
}