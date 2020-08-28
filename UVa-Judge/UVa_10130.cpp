#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int n;
vector <int> wgt, val;
int memo[1100][30000];

int dp(int idx, int cap){
	if (cap < 0) return -INF;
	if (idx == n) return 0;

	int &curr = memo[idx][cap];

	if (curr != -1) 
		return curr;

	curr = max(dp(idx+1, cap), val[idx]+dp(idx+1, cap-wgt[idx]));

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		cin >> n;
	
		wgt.resize(n); val.resize(n);	

		int mem[40] = {};	

		for (int i = 0; i < n; i++){
			cin >> val[i] >> wgt[i];
			for (int j = 30; j >= wgt[i]; j--){
				if (mem[j] < mem[j-wgt[i]]+val[i])
					mem[j] = mem[j-wgt[i]]+val[i];
			}
		}
	
		int g; cin >> g;

		int ans = 0;

		//memset(memo, -1, sizeof memo);

		while (g--){
		 	int c; cin >> c;
		 	ans += mem[c];
		}

		cout << ans << endl;
	}

	return 0;
}