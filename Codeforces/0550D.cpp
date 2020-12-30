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

	int n; cin >> n;

	if (n%2 == 0){
		cout << "NO" << endl;
		exit(0);
	}
	cout << "YES" << endl;
	if (n == 1){
		cout << "2 1" << endl << "1 2" << endl;
		exit(0);
	}
	
	vector <pair<int, int>> ans;

	for (int i = 2; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			if (i + 1 != j){
				ans.push_back({i, j});
				ans.push_back({n+i, n+j});
			}
		}
	}

	for (int i = 3; i+1 <= n; i += 2){
		ans.push_back({i, i+1});
		ans.push_back({n+i, n+i+1});
	}

	for (int i = 2; i <= n; i++){
		ans.push_back({1, i});
		ans.push_back({n+1, n+i});
	}

	ans.push_back({1, n+1});

	int k = 2*n;
	for (int i = 2; i <= n; i++){
		ans.push_back({i, k+1});
		ans.push_back({i, k+2});
		ans.push_back({n+i, k+3});
		ans.push_back({n+i, k+4});
	}

	ans.push_back({k+1, k+2});
	ans.push_back({k+3, k+4});

	cout << 2*n + 4 << " " << ans.size() << endl;
	for (auto x : ans)
		cout << x.first << " " << x.second << endl;

	return 0;
}