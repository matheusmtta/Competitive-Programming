#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int memo[200][200][200];
vector <int> piles[3];

int dp(int i, int j, int k){
	//cout << i << " " << j << " " << k << endl;
	int a = piles[0][i];
	int b = piles[1][j];
	int c = piles[2][k];  
	if (a == -1 &&
		b == -1 &&
		c == -1)
		return 1;

	int &curr = memo[i][j][k];

	if (curr != -1)
		return curr;

	curr = 0;

	if ((a != -1 && b != -1 && c != -1) && (a+b+c)%3 == 0){
		curr = max(curr, dp(i-1, j-1, k-1));
	}

	if ((a != -1 && b != -1) && (a+b)%3 == 0)
		curr = max(curr, dp(i-1, j-1, k));
	if ((a != -1 && c != -1) && (a+c)%3 == 0)
		curr = max(curr, dp(i-1, j, k-1));
	if ((b != -1 && c != -1) && (b+c)%3 == 0)
		curr = max(curr, dp(i, j-1, k-1));

	if (a != -1 && a%3 == 0)
		curr = max(curr, dp(i-1, j, k));
	if (b != -1 && b%3 == 0)
		curr = max(curr, dp(i, j-1, k));
	if (c != -1 && c%3 == 0)
		curr = max(curr, dp(i, j, k-1));

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; 

	while (cin >> n){
		if (n == 0) exit(0);
		for (int i = 0; i < 3; i++)
			piles[i].push_back(-1);

		for (int i = 0; i < n; i++){
			int a, b, c; 
			cin >> a >> b >> c;
			piles[0].push_back(a);
			piles[1].push_back(b);
			piles[2].push_back(c);
		}

		memset(memo, -1, sizeof memo);

		cout << dp(n, n, n) << endl;

		for (int i = 0; i < 3; i++)
			piles[i].clear();
	}

	return 0;
}