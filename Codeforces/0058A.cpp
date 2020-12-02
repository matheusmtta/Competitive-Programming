#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

string a, b;
int memo[110][110];

int LCS(int i, int j){
	if (i == a.size() || j == b.size())
		return 0;

	int &curr = memo[i][j];

	if (curr != -1) return curr;

	curr = 0;

	if (a[i] == b[j]) curr = max(curr, 1 + LCS(i+1, j+1));

	return curr = max({curr, LCS(i+1, j), LCS(i, j+1)});
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a;
	b = "hello";

	memset(memo, -1, sizeof memo);

	LCS(0, 0) == b.size() ? cout << "YES" << endl : cout << "NO" << endl;

	return 0;
}
