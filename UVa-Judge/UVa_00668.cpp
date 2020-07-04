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
		vector <int> ans;
		for (int i = 2; i <= n; i++){
			ans.push_back(i);
			n -= i;
		}
		int i = ans.size()-1;
		
		while (n > 0 && i >= 0){
			ans[i]++;
			i--; n--;
		}

		if (n > 0) ans[ans.size()-1] += n;
		
		for (int k = 0; k < ans.size(); k++){
			cout << ans[k];
			if (k != ans.size()-1) cout << " ";
		}
		cout << endl;
		if (t) cout << endl;
	}

	return 0;
}