#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		int a, b, k; cin >> a >> b >> k;
		vector <int> boys(a+1), girls(b+1);
		vector <pair<int, int>> e(k); 

		for (int i = 0; i < k; i++){
			int xy; cin >> xy;
			boys[xy]++;
			e[i].f = xy;
		}

		for (int i = 0; i < k; i++){
			int xx; cin >> xx;
			girls[xx]++;
			e[i].s = xx;
		}

		int64 ans = 0;
		for (int i = 0; i < k; i++){
			ans += k - (boys[e[i].f] + girls[e[i].s]) + 1;
		}
		
		cout << (ans >> 1) << endl;
	}

	return 0;
}