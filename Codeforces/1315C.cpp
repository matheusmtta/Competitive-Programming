#include <bits/stdc++.h>

using namespace std;

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

		vector <int> arr(n);

		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}

		vector <int> basis((2*n)+1, 0);

		vector <int> ans(n*2);

		bool rsp = true;

		int k = 0;

		for (int i = 0; i < n*2; i += 2){
			if (basis[arr[k]]) {rsp = false; break;}
			basis[arr[k]] = 1;
			ans[i] = arr[k];
			k++;
		}

		for (int i = 0; i < ans.size(); i+=2){
			for (int j = ans[i]+1; j < basis.size(); j++){
				if (!basis[j]){
					ans[i+1] = j;
					basis[j] = 1;
					break;
				}
			}
		}

		for (int i = 0; i < ans.size(); i++){
			if (ans[i] == 0) rsp = false;
		}

		if (!rsp) {cout << -1 << endl;}
		else{
			for (int i = 0; i < ans.size(); i++){
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}	

	return 0;
}