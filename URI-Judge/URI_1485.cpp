#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back
#define MAX 260

typedef long long int int64;
typedef unsigned long long int  uint64;

int memo[MAX][MAX][MAX];
int cmpt[MAX][MAX][MAX];

int S, B; 
vector <int> roullet;
vector <int> balls;

int dp(int i, int j, int k){
	if (j == B) return 0;

	int &curr = memo[i][j][k];

	if (cmpt[i][j][k])
		return curr;
	if ((k+1)%S == i || ((k+2)%S == i && j != B-1) || cmpt[i][j][(k+1)%S])
	    curr = INF;
	else {
		int value = balls[j]*(roullet[k]+roullet[(k+1)%S]);
		cmpt[i][j][k] = true;
		curr = min(dp(i, j, (k+1)%S), value+dp(i, j+1, (k+2)%S));
	}

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> S >> B){
		if (S == 0 && B == 0) exit(0);

		roullet.resize(S);
		balls.resize(B);

		for (auto &x : roullet)
			cin >> x;

		for (auto &x : balls)
			cin >> x;

		int ans = INF;

		memset(cmpt, false, sizeof cmpt);
		memset(memo, INF, sizeof memo);

		for (int i = 0; i < S; i++)
			ans = min(dp(i, 0, i), ans);

		cout << -1*ans << endl;
	}

	return 0;
}