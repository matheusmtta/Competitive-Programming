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
		int n; cin >> n;
		vector <int64> a;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			a.push_back(x);
		}

		sort(a.begin(), a.end());

		int i = 0, j = a.size()-1;

		vector <int64> ans;
 
		while (i <= j){
			if (i == j) ans.push_back(a[i]);
			else{
				ans.push_back(a[i]);
				ans.push_back(a[j]);
			}
			i++; j--;
		}

		reverse(ans.begin(), ans.end());

		for (auto k : ans)
			cout << k << " ";
		cout << endl;
	}

	return 0;
}