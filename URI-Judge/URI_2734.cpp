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
int n; 
int memo[201][5050];

int dp(int i, int j, int k){
	if (j < 0)
		return -INF;
	if (k == n)
		return 0;
	if (i == 2*n && (k < n || k > n))
		return -INF;

	int &curr = memo[i][j];

	if (curr != -1)
		return memo[i][j];

	curr = max(dp(i+1, j, k), dp(i+1, j-arr[i], k+1) + arr[i]);

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		cin >> n;

		int sum = 0;
		arr.resize(2*n);
		
		for (int &x : arr){
			cin >> x;
			sum += x;
		}

		memset(memo, -1, sizeof memo);

		cout << sum - 2*dp(0, sum/2, 0) << endl;
	}

	return 0;
}