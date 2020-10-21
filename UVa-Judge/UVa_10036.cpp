#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, k;
int memo[10100][101];
vector <int> arr;

int dp(int idx, int sum){
	if (idx == n)
		return sum == 0 ? 1 : 0;

	int &curr = memo[idx][sum];
	
	if (curr != -1)
		return curr;

	curr = 0;

	curr = max(dp(idx+1, ((sum + arr[idx])%k+k)%k), dp(idx+1, ((sum - arr[idx] + k)%k+k)%k));

	return curr;
}

string recover(int idx, int sum){
	
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		cin >> n >> k;

		arr.resize(n);

		for (int &x : arr){
			cin >> x;
			if (x < 0){
				int c = abs((x/k)) + 1;
				x = (c*k) + x;
			}
			x %= k;
		}

		memset(memo, -1, sizeof memo);

		int ans = dp(0, 0);

		if (ans)
			cout << "Divisible" << endl;
		else
			cout << "Not divisible" << endl;
	}

	return 0;
}