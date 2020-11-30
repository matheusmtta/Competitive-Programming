 
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

	string a, b; cin >> a >> b;

	for (int i = 0; i < (int)a.size(); i++){
		if (a[i] <= 'Z' && a[i] >= 'A')
			a[i] = a[i] - ('Z' - 'z');
		if (b[i] <= 'Z' && b[i] >= 'A')
			b[i] = b[i] - ('Z' - 'z');
	}

	int ans = 0;

	for (int i = 0; i < (int)a.size(); i++){
		if (a[i] > b[i])
			ans++;
		if (a[i] < b[i])
			ans--;
	}

	if (a > b) cout << 1 << endl;
	else if (a == b) cout << 0 << endl;
	else cout << -1 << endl;

	return 0;
}
