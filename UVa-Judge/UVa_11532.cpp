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

	int64 t; cin >> t;

	while (t--){
		int64 P, Q; cin >> P >> Q;
		int64 k = 0, ans = 0;
		while (P >= 2 && Q >= 1){
			ans |= (1LL << k)|(1LL << (k+2));
			k += 3; 
			P -= 2;
			Q--;
		}
		if (P == 1 && Q >= 1){
			ans |= 1LL << k;
			P--;
			Q--;
			k += 2;
		}
		for (int i = 0; i < P; i++){
			ans = (ans << 1LL)|1;
		}
		cout << ans << endl;
	}

	return 0;
}