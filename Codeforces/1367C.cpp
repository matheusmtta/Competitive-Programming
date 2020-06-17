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
		int n, k; cin >> n >> k;
		
		string str; cin >> str;

		string aux;

		for (int i = 0; i < k; i++)
			aux += '0';

		str = '1' + aux + str + aux + '1';

		int lst = 0, ans = 0;

		for (int i = 1; i < str.size(); i++){
			if (str[i] == '1'){
				int tmp = i-lst-1;
				lst = i;
				tmp -= k;

				if (tmp > 0)
					ans += tmp/(k+1);
			}
		}

		cout << ans << endl;
	}

	return 0;
}