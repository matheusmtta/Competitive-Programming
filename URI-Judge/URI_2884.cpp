#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 1010;

map <int, bitset <MAX>> a;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;

	bitset <MAX> b;

	int k; cin >> k;

	for (int i = 0; i < k; i++){
		int x; cin >> x;
		b[x] = 1;
	}

	for (int i = 0; i < n; i++){
		int k; cin >> k;
		for (int j = 0; j < k; j++){
			int x; cin >> x;
			a[i].set(x);
		}
	}

	int ans = 0;
	int p = 0, l = 0;

	while (b.count() && l != 100000){
		b ^= a[p];
		p = (p+1)%n;
		ans++;
		l++;
	}

	if (b.count() == 0) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}