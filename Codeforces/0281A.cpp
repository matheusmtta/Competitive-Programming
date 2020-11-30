 
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

	string a; cin >> a;
	if (a[0] >= 'a' && a[0] <= 'z')
		a[0] = a[0] + ('Z' - 'z');
	cout << a << endl;

	return 0;
}
