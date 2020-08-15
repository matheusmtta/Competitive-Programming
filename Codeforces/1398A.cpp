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

	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector <int> arr(n);
		for (auto &x : arr)
			cin >> x;
		if (arr[0]+arr[1] <= arr[n-1])
			cout << "1 2 " << n << endl;
		else cout << -1 << endl;
	}

	return 0;
}