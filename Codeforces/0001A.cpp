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

	int64 n, m, a; cin >> n >> m >> a;
	cout << (n/a + (n%a > 0 ? 1 : 0))*(m/a + (m%a > 0 ? 1 : 0)) << endl;

	return 0;
}