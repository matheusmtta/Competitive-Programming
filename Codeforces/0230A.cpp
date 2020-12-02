#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int s, n; cin >> s >> n;
	vector <pair<int, int>> arr;
	for (int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		arr.push_back({x, y});
	}
	sort(arr.begin(), arr.end());
	bool flag = true;
	for (int i = 0; i < n; i++){
		if (s <= arr[i].first)
			flag = false;
		else
			s += arr[i].second;
	}

	flag ? cout << "YES" << endl : cout << "NO" << endl;

	return 0;
}
