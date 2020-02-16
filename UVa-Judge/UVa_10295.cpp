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

	int n, m; cin >> n >> m;

	map <string, int> mp;

	for (int i = 0; i < n; i++){
		int a; string str; cin >> str >> a;
		mp[str] = a;
	}

	string tmp;
	int ans = 0;

	while (cin >> tmp && m){
		if (tmp == ".") {m--; cout << ans << endl; ans = 0;}
		ans += mp[tmp];
	}

	return 0;
}