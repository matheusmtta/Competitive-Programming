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
	
	vector <int64> arr(n);
	for (int64 &x : arr) cin >> x;

	sort(arr.begin(), arr.end());

	int64 ans = 0;

	for (int i = 1; i <= n; i++)
		ans += abs(i - arr[i-1]);

	cout << ans << endl;

	return 0;
}