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

	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		int lst = 0, ans = 0;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			if (i == 0){
				ans = 1;
			}
			else {
				if (ans%2){
					if (x < lst) ans++;
				}
				else{
					if (x > lst) ans++;
				}
			}
			lst = x;
		}
		cout << ans << endl;
	}

	return 0;
}