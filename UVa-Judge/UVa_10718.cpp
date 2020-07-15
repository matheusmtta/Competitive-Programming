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

	int64 N, L, U;
	while (cin >> N >> L >> U){
		int64 M = 0;
		for (int i = 31; i >= 0; i--){
			if (M+(1LL << i)-1 < L){
				M += (1LL << i);
				continue;
			}
			else if (!(N & (1LL << i)) && M+(1LL << i) <= U)
				M += (1LL << i);
		}
		cout << M << endl;
	}	

	return 0;
}