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
		string str;
		cin >> str;

		string ans;

		ans += str[0];
		bool flag = false;

		for (int i = 1; i < str.size()-1; i++){
			if (i%2 == 1){
				ans += str[i];
			}
		}

		ans += str[str.length()-1];

		cout << ans << endl;
	}

	return 0;
}