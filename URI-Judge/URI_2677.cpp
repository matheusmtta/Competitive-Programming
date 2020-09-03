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
int memo[1200][1200];

int dp(int i, int j, int flag){
	if (i > j)
		return 0;

	int &curr = memo[i][j];

	if (curr != -1)
		return curr;

	curr = 0;

	if (arr[i]%2 == arr[j]%2){
		if (!flag)
			curr = max((arr[i]%2 == 0 ? 1 : 0) + dp(i+1, j, flag^1),
					   (arr[j]%2 == 0 ? 1 : 0) + dp(i, j-1, flag^1)); 
		else 
			curr = min(dp(i+1, j, flag^1), dp(i, j-1, flag^1));
	}
	else if (arr[i]%2 == 0 && arr[j]%2 == 1)
			curr = (flag ? 0 : 1) + dp(i+1, j, flag^1);
	else if (arr[i]%2 == 1 && arr[j]%2 == 0)
			curr = (flag ? 0 : 1) + dp(i, j-1, flag^1);

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; 

	while (cin >> n){
		if (n == 0)
			exit(0);
		arr.resize(2*n);

		for (auto &x : arr)
			cin >> x;

		memset(memo, -1, sizeof memo);

		cout << dp(0, (2*n)-1, 0) << endl;
		//cout << "-----------" << endl;
	}

	return 0;
}