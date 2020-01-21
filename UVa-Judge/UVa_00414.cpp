#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while (cin >> n){
		if (n == 0) return 0;
		getchar();

		int mx = 100000, count[n];

		for (int i = 0; i < n; i++)
			count[i] = 0;

		for (int i = 0; i < n; i++){
			string str; getline(cin, str);
			for (int j = 0; j < str.length(); j++){
				if (str[j] == ' ') count[i]++;
			}

			mx = min(count[i], mx);
		}

		int ans = 0;

		for (int i = 0; i < n; i++)
			ans += abs(mx - count[i]);

		if (n != 1) cout << ans << endl;
		else cout << 0 << endl;
	}
}