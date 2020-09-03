#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	
	vector <int> blocks(n);

	for (auto &x : blocks)
		cin >> x;

	for (int i = 0; i < n; i++) {
		if (i == 0 && blocks[i] > 0){
			blocks[i] = 1;
		}
		else if (blocks[i] > blocks[i-1])
			blocks[i] = blocks[i-1]+1;
	}

	for (int i = n-1; i >= 0; i--) {
		if (i == n-1 && blocks[i] > 0)
			blocks[i] = 1;
		else if (blocks[i] > blocks[i+1])
			blocks[i] = blocks[i+1]+1;
	}

	int ans = 0;

	for (auto x : blocks)
		ans = max(ans, x);

	cout << ans << endl;

	return 0;
}