#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while (1){
		cin >> n; if (n == 0) break;

		string str;

		cin >> str;

		int init = 0;
		int s = str.length() - 1;

		int j = str.length()/n;

		for (int i = 0; i < str.length(); i += j){
			if (s < init+i+j-1) break;
			reverse(str.begin()+i, str.begin()+i+j);
		}

		cout << str << endl;
	}
}