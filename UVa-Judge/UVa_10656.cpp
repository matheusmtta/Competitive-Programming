#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while (cin >> n){
		vector <int> ans;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			if (x != 0) ans.push_back(x);
		}
		if (ans.size() == 0) cout << 0 << endl;
		else {
			cout << ans[0];
			for (int i = 1; i < ans.size(); i++)
				cout << " " << ans[i];
			cout << endl;
		}
	}
}