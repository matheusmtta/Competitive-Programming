#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
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
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				char x; cin >> x;
				if (x == '1')
					cout << '9';
				else
					cout << x;
			}
			cout << endl;
		}
	}	
 
	return 0;
}