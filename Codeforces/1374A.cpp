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

	int64 x, y, n;
	//k mod x = y
	int t; cin >> t;

	while (t--){
		cin >> x >> y >> n;
		int64 aux = n/x;
		(x*(aux))+y > n ? cout << (x*(aux-1))+y << endl : cout << (x*(aux))+y << endl;
	}

	return 0;
}