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

	int n; cin >> n;

	vector <int32> b(n, 0);

	for (int i = 0; i < n; i++){
		cin >> b[i];
	}

	int y = 0;

	vector <int32> a(n, 0);
	int32 mx = 0;

	for (int i = 0; i < n; i++){
		if (i == 0) {a[i] = b[i]; mx = max(mx, a[i]);}
		else {
			a[i] = b[i] + mx;
			mx = max(mx, a[i]);
		}
	}

	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}