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
		int a, b, sa, sb;
		cin >> a >> b >> sa >> sb;

		int dist = b - a;
		int aux = dist/(sa+sb);
		int aux2 = dist%(sa+sb);

		if (aux2 == 0) cout << aux << endl;
		else cout << -1 << endl;
 	}

	return 0;
}