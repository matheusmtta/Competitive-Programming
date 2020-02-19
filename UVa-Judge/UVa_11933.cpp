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

	while (true){
		int64 n; cin >> n;
		
		if (n == 0) return 0;

		int64 a = 0, b = 0, p = 1;

		for (int i = 0; (1LL << i) <= n; i++){
			if (p && n&(1LL << i)){
				a = a|(1LL << i);
				p = !p;
			}
			else if (!p && n&(1LL << i)){
				b = b|(1LL << i);
				p = !p;
			}
		}

		cout << a << " " << b << endl;
	}

	return 0;
}