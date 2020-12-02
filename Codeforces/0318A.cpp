#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define end "\n"
#define first f
#define second s
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64 n, k; cin >> n >> k;

	if (k > (n+1)/2)
		cout << 2*(k - ((n+1)/2)) << endl;
	else
		cout << 2*k-1 << endl;	

	return 0;
}
