#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int R, G, B;

vector <int> r(300, 0), g(300, 0), b(300, 0);
int64 memo[300][300][300];

int comp(const int &a, const int &b){
	return a > b;
}

int64 dp(int i, int j, int k){
	bool flagR = i == R, flagG = j == G, flagB = k == B;
	int64 &curr = memo[i][j][k];
	if (curr != -1)
		return curr;
	curr = 0;
	if (!flagR && !flagG)
		curr = max(curr, r[i]*g[j]+dp(i+1, j+1, k));
	if (!flagR && !flagB)
		curr = max(curr, r[i]*b[k]+dp(i+1, j, k+1));
	if (!flagG && !flagB)	
		curr = max(curr, g[j]*b[k]+dp(i, j+1, k+1));
	return curr;
}	

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> G >> B;
	for (int i = 0; i < R; i++){
		int x; cin >> x;
		r.push_back(x);
	}

	for (int i = 0; i < G; i++){
		int x; cin >> x;
		g.push_back(x);
	}

	for (int i = 0; i < B; i++){
		int x; cin >> x;
		b.push_back(x);
	}

	sort(r.begin(), r.end(), comp);
	sort(g.begin(), g.end(), comp);
	sort(b.begin(), b.end(), comp);

	memset(memo, -1, sizeof memo);

	cout << dp(0, 0, 0) << endl;

	return 0;
}