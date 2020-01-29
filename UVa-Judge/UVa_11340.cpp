#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	while(n--){
		map <char, int> pay;
		int p; cin >> p;

		for (int i = 0; i < p; i++){
			char x; int k;
			cin >> x >> k;
			pay.insert({x, k});
		}

		int m; cin >> m;

		string str;
		
		double ans = 0;

		cin.ignore();

		for (int i = 0; i < m; i++){
			getline(cin, str);

			for (int j = 0; j < str.length(); j++){
				if (pay.count(str[j])){
					ans += pay[str[j]];
				}
			}
		}

		printf("%.2lf$\n", ans/100);
	}
}