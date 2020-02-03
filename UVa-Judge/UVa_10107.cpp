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
	int64 n;
	vector <int> ans;
	while (cin >> n){
		ans.push_back(n);
		sort(ans.begin(), ans.end());

		if (ans.size()%2 != 0)
			cout << ans[ans.size()/2] << endl;
		else
			cout << (ans[(ans.size()/2)-1]+ans[(ans.size()/2)])/2 << endl;
	}
	
	return 0;
}