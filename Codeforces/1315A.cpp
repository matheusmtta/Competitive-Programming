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
		int a, b, x, y;
		cin >> a >> b >> x >> y;

		int rsp1 = min(abs(a - (x+1)+1), (x+1));
		int rsp2 = min(abs(b - (y+1)+1), (y+1));

		int ans = min(b*rsp1, a*rsp2);

		cout << (a*b)-ans << endl;

		cout << "-------------" << endl;
 	}	

	return 0;
}