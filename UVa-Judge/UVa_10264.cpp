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

	int n;

	while (cin >> n){
		int sz = 1 << n;

		vector <int> w(sz, 0);
		bitset <32769> aux;

		for (int i = 0; i < sz; i++){
			int x; cin >> x;
			for (int j = 0; j < sz; j++){
				int k = i ^ j;
				if (i != j && (k && (!((k-1) & k)))) w[j] += x;
			}
		}

		int ans = -1;


		for (int i = 0; i < sz; i++){
			for (int j = 0; j < sz; j++){
				int k = i ^ j;
				if (!(k && (!((k-1) & k))) || i == j) continue;
				ans = max(ans, w[i]+w[j]);
			}
		}

		cout << ans << endl;
	}	

	return 0;
}