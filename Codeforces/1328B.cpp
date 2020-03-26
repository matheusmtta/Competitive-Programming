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
		int a, b; cin >> a >> b;

		string ans;

		for (int i = 0; i < a; i++)
			ans += "a";

		if (b == 1) {ans[a-1] = 'b'; ans[a-2] = 'b';}
		else {
			int64 n = 1;
			
			n = (2*sqrt(b))+1;
			
			int64 sum = n*(n+1);
			sum/=2;
			int64 i = a-n-1;
			int64 j = i + (sum-b+1);
			ans[i] = 'b';
			ans[j] = 'b';
		}
		cout << ans << endl;
	}

	return 0;
}