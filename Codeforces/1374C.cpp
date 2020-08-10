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
		string str; cin >> str;
		int o, c;
		o = c = 0;
		int x, y;
		x = 0; y = 0;
		for (int i = 0; i < n; i++){
			if (str[i] == ')'){
				if (o == 0)
					x++;
				else {
					o--;
				}
			}
			else {
				o++;
			}
		}
		cout << min(x, o) << endl;
	}	

	return 0;
}