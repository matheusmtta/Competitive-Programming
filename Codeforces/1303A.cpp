#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

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

		int lst = -1;
		int ans = 0;

		for (int i = 1; i < str.length(); i++){
			if (lst != -1 && str[i] == '1' && str[i - 1] == '0'){
				ans += abs(i-1 - lst)+1;
			}
			else if (str[i-1] == '1' && str[i] == '0'){
				lst = i;
			}
		}

		cout << ans << endl;
	}

	return 0;
}