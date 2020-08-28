#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int N, Q, M, D;
vector <int> val;
//idx, sum, num
int64 memo[210][200][200];

int64 dp(int idx, int k, int64 sum){	
	if (k == 0 && sum == 0)
		return 1;

	if (idx == N || k <= 0)
		return 0;

	int64 &curr = memo[idx][k][sum];

	if (curr != -1)
		return curr;

	curr = dp(idx+1, k, sum) + dp(idx+1, k-1, ((sum+val[idx])%D + D)%D);

	return curr;
}															

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q = 1;
	while (cin >> N >> Q){
		if (N == 0 && Q == 0) return 0;
		for (int i = 0; i < N; i++){
			int x; cin >> x;
			val.push_back(x);
		}
		cout << "SET " << q++ << ':' << endl;
		for (int i = 0; i < Q; i++){
			cout << "QUERY " << i+1 << ": ";
			memset(memo, -1, sizeof memo);
			cin >> D >> M;
			cout << dp(0, M, 0) << endl;
		}
		val.clear();
	}	

	return 0;
}