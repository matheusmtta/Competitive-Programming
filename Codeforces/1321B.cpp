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

map <int, int> mp;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector <int> arr;

	int n; cin >> n;

	for (int i = 0; i < n; i++){
		int x; cin >> x;
		arr.push_back(x);
	}

	
	int64 ans = -1;

	map <int, int64> mp;

	for (int i = 0; i < n; i++){
		mp[arr[i]-i] += arr[i];
	}

	for (auto i : mp){
		ans = max(i.second, ans);
	}

	cout << ans << endl;

	return 0;
}