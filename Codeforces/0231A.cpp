 
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

	int n; cin >> n;

	int ans = 0;

	for (int i = 0; i < n; i++){
		int k = 0;
		for (int j = 0; j < 3; j++){
			int x; cin >> x;
			if (x == 1){
				k++;
			}
		}
		if (k >= 2)
			ans++;
	}
	
	cout << ans << endl;

	return 0;
}
