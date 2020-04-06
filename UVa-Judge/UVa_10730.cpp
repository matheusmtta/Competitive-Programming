#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin >> n){
		if (n == 0)
			exit(0);

		char c; cin >> c;

		vector <int> a(n);

		for (int i = 0; i < n; i++)
			cin >> a[i];

		vector <int> find(n);

		bool ans = true;

		for (int i = 0; i < n; i++){
			find.assign(n, 0);
			
			for (int j = 0; j <= i; j++)
				find[a[j]] = 1;

			find[a[i]] = 1;

			for (int j = i+1; j < n; j++){
				int ratio = a[j] - a[i];
				if ((a[j] + ratio > 0 && a[j] + ratio <= n) && !find[a[j]+ratio]){
					ans = false;
					break;
				}
				find[a[j]] = 1;
			}
		}

		if (ans) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}