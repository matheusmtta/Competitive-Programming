 
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
	string mgt; cin >> mgt;

	int ans = 1;
	int lst = mgt[0] == '1' ? 1 : 0;
	
	for (int i = 1; i < n; i++){
		cin >> mgt; int curr = mgt[0] == '1' ? 1 : 0;
		if (curr == lst)
			continue;
		else{
			ans++;
			lst ^= 1;
		}
	}

	cout << ans << endl;

	return 0;
}
