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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int N, M; cin >> N >> M;
		map <int, int> a, b;
		set <int> c;

		for (int i = 0; i < N; i++){
			int x; cin >> x;
			a[x]++;
			c.insert(x);
		}

		for (int i = 0; i < M; i++){
			int x; cin >> x;
			b[x]++;
			c.insert(x);
		}

		int32 ans = 0;

		for (auto i : c){
			ans += abs(a[i] - b[i]);
		}

		cout << ans << endl;
	}

	return 0;
}