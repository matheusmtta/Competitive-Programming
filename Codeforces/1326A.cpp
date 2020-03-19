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
 
	int t; cin >> t;
 
	while (t--){
		int x; cin >> x;
 
		int ans = false;
 
		if (x == 1) {cout << -1 << endl; continue;}
		else{
			string str;
			int sum = 0;
			for (int i = 0; i < x-2; i++){
				str += '2';
				sum += 2;
			}
			if ((sum+5)%3 != 0) cout << str << 2 << 3 << endl;
			else if ((sum+2+9)%9) cout << str << 2 << 9 << endl;
			else if ((sum+3+9)%9 != 0 && (sum+3+9)%3) cout << str << 3 << 9 << endl; 
		}
	}
 
	return 0;
}