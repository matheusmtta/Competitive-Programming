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

	int n; cin >> n;
	string str; cin >> str;

	char mn0 = 'a', mn1 = 'a';

	string ans;

	for (int i = 0; i < str.length(); i++){
		if (str[i] - 'a' >= mn0 - 'a'){
			ans += '0';
			mn0 = str[i];
		}
		else if (str[i] - 'a' >= mn1 - 'a'){
			ans += '1';
			mn1 = str[i];
		}
		else{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	cout << ans << endl;

	return 0;
}