#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int n;
int memo[10100][10];
vector <int> arr;

int dp(int idx, int diff, int a, int b){
	if (idx == n)
		return 1;

	int &curr = memo[idx][diff];

	if (memo[idx][diff] != -1)
		return curr;

	curr = 0;

	if (abs(a+arr[idx] - b) <= 5)
		curr = max(curr, dp(idx+1, abs(a+arr[idx] - b), a+arr[idx], b));
	if (abs(b+arr[idx] - a) <= 5)
		curr = max(curr, dp(idx+1, abs(b+arr[idx] - a), a, b+arr[idx]));

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		cin >> n;
		arr.resize(n);

		for (auto &x : arr)
			cin >> x;

		memset(memo, -1, sizeof memo);

		dp(0, 0, 0, 0) ? cout << "Feliz Natal!" << endl : cout << "Ho Ho Ho!" << endl;
	}

	return 0;
}