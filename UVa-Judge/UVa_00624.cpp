#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAXN = 1000;
const int MAXW = 1000;

int memo[MAXN][MAXN];
vector <int> g;
vector <int> r;
int limit;
int k;

int dp(int idx, int capacity){
	if (capacity < 0) return -INF;
	if (idx == k) return 0;
	int &q = memo[idx][capacity];
	if (q != -1) return q;
	return q = max(dp(idx+1, capacity), g[idx] + dp(idx+1, capacity-g[idx]));
}

void recover(int idx, int capacity){
	if (idx == k) return;

	int pick = g[idx] + dp(idx+1, capacity-g[idx]);
	int left = dp(idx+1, capacity);

	if (pick >= left){
		r.push_back(idx);
		recover(idx+1, capacity-g[idx]);
	}
	else 
		recover(idx+1, capacity);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; 

	while (cin >> limit){
		cin >> k;

		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXW; j++)
				memo[i][j] = -1;

		for (int i = 0; i < k; i++){
			int x; cin >> x;
			g.push_back(x);
		}

		int ans = dp(0, limit);



		recover(0, limit);

		for (auto i : r)
			cout << g[i] << " ";
		cout << "sum:" << ans << endl;

		r.clear();
		g.clear();
	}

	return 0;
}