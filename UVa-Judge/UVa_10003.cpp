#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> arr;

int memo[55][55];

int dp(int left, int right){
	int &curr = memo[left][right];
	if (curr != -1)
		return curr;
	if (left + 1 == right)
		return curr = 0;

	curr = INF;

	for (int i = left + 1; i < right; i++)
		curr = min(curr, dp(left, i) + dp(i, right) + arr[right] - arr[left]);

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int l;

	while (cin >> l){
		if (l == 0)
			return 0;

		int n; cin >> n;
		arr.resize(n+2);
		
		arr[0] = 0;
		arr[n+1] = l;

		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		memset(memo, -1, sizeof memo);

		cout << "The minimum cutting is " << dp(0, n+1) << "." << endl;
	}

	return 0;
}
