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

	int n, m; cin >> n >> m;

	vector <int> arr(m);
	for (auto &x : arr)
		cin >> x;
	
	sort(arr.begin(), arr.end());
	
	int ans = INF;

	for (int i = 0; i <= m-n; i++)
		ans = min(ans, arr[i+n-1]-arr[i]);

	cout << ans << endl;

	return 0;
}
