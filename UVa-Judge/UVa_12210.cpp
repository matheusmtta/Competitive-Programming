#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q = 1; 

	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		vector <int> b, s;
		int mn = INF;
		
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			mn = min(x, mn);
		}

		for (int j = 0; j < m; j++){
			int x; cin >> x;
		}

		int diff = n - m;

		cout << "Case " << q << ": ";
		if (diff > 0) cout << diff << " " << mn << endl;
		else cout << 0 << endl;
		q++;
	}

	return 0;
}