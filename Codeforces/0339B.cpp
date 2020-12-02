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
 
	string s; cin >> s;
	int n = s.size();
 
	bool flag = true;
 
	for (int i = 0; i < n; i++){
		if (i+2 < n && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
			if (!flag) cout << ' ';
			flag = true;
			i += 2;
		}
		else{
			cout << s[i];
			flag = false;
		}
	}
	cout << endl;
 
	return 0;
}