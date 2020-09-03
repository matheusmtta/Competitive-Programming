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

int n, m, k;
double memo[1100][200];
bool calc[1100][200];
vector <int> hp, boost;

double dp(int idx, int mana){
	if (idx == n)
		return 0;

	double &curr = memo[idx][mana];
	
	if (calc[idx][mana])
		return curr;

	curr = INF;
	calc[idx][mana] = true;

	if (mana > 0){
		double ratio = (double)hp[idx]/((double)k + (double)boost[idx]);
		curr = ratio + dp(idx+1, mana-1);
	}
	double ratio = (double)hp[idx]/(double)k;
	curr = min(curr, ratio + dp(idx+1, mana));

	return curr;
}

int main(){	
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	while (cin >> n >> m >> k){
		hp.resize(n); boost.resize(n);

		for (int i = 0; i < n; i++)
			cin >> hp[i] >> boost[i];

		memset(memo, 0, sizeof memo);
		memset(calc, false, sizeof calc);

		double ans = dp(0, m);

		printf("%.4lf\n", ans);
	}

	return 0;
}