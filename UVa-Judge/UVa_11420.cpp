#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, s;
int64 memo[70][70][3];

int64 dp(int idx, int sec, int lst){
	if (idx == n) return sec == s ? 1 : 0;

	int64 &curr = memo[idx][sec][lst];

	if (curr != -1) return curr;

	curr = dp(idx+1, sec, 0) + (lst == 1 ? dp(idx+1, sec+1, 1) : dp(idx+1, sec, 1));

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> s){
		if (n < 0 && s < 0)
			return 0;
		memset(memo, -1, sizeof memo);
		cout << dp(0, 0, 1) << endl;
	}	

	return 0;
}