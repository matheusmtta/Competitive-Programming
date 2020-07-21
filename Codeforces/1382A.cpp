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

	int t; cin >> t;

	while (t--){
		int n, m; cin >> n >> m;
		vector <int> aux(10000, 0);
		bool flag = true;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			aux[x] = 1;
		}
		for (int i = 0; i < m; i++){
			int x; cin >> x;
			if (aux[x] && flag) {cout << "YES" << endl << "1 " << x << endl; flag = false;}
		}
		if (flag) cout << "NO" << endl;
	}

	return 0;
}