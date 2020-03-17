#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;  

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true){
		int n; cin >> n;
		vector <int> arr(n);

		if (n == 0) exit(0);

		int b = INF;

		for (int i = 0; i < n; i++){
			cin >> arr[i];
			if (arr[i] == 1) b = min(b, i);
		}

		if (b == INF) {cout << ((n+1)*2)/4 << endl; continue;}

		int count = 0;

		int i = b;

		int ans = 0;

		while (count <= n){
			int sz = 0;
			while (arr[b] == 0 && count != n){
				sz++;
				count++;
				b = (b+1)%n;
			}
			if (sz*2 >= 4) ans += (sz*2)/4;
			count++;
			b = (b+1)%n;
		}

		cout << ans << endl;
	}
	
	return 0;
}