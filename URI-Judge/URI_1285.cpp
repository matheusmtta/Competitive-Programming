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

	int n, m;

	while (cin >> n >> m){
		int ans = 0;
		for (int i = n; i <= m; i++){
			string str = to_string(i);
			set <char> aux;
			for (int j = 0; j < str.length(); j++){
				aux.insert(str[j]);
			}
			if (aux.size() == str.length()) ans++;
		}
		cout << ans << endl;
	}
	
	return 0;
}