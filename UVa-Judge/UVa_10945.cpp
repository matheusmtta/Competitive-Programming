#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	int n; cin >> n;
	while (n--){
		cin >> str;
		string phr;

		for (int i = 0; i < str.length(); i++){
			if (str[i] >= 'a' && str[i] <= 'z') phr += str[i];
		}

		int i = 0, j = phr.length() - 1, ans = 0;

		while (i < j){
			if (phr[i] == phr[j]) ans++;
			i++; j--;
		}

		if (ans == phr.length()/2) cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.." << endl;
	}
}