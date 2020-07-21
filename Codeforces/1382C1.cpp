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
		string a, b; 
		vector <int> ans;
		cin >> a >> b;
		int count = 0;
		for (int i = 0; i < n; i++){
			if (a[i] != b[i]){
				ans.push_back(i+1);
				if (i != 0) count += 3;
				else count++;
			}
		}
		cout << count << " ";
		for (auto k : ans){
			if (k == 1) cout << 1 << " ";
			else cout << k << " " << 1 << " " << k << " ";
		}
		cout << endl;
	}

	return 0;
}