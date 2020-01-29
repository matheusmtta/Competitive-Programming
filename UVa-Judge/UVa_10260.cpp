#include <bits/stdc++.h>

using namespace std;

int main(){

	char key[1000];

	key['1'] = key['B'] = key['F'] = key['P'] = key['V'] = '1';
	key['2'] = key['C'] = key['G'] = key['J'] = key['K'] = key['Q'] = key['S'] = key['X'] = key['Z'] = '2';
	key['3'] = key['D'] = key['T'] = '3';
	key['4'] = key['L'] = '4';
	key['5'] = key['M'] = key['N'] = '5';
	key['6'] = key['R'] = '6';

	string str;
	char lst;

	while (cin >> str){
		string ans;
		char lst = '@';
		for (int i = 0; i < str.length(); i++){
			if (!(str[i] == 'A' || str[i] == 'E' ||
			    str[i] == 'I' || str[i] == 'O' ||
			    str[i] == 'U' || str[i] == 'H' ||
			    str[i] == 'W' || str[i] == 'Y')){
				if (key[str[i]] != key[lst]){
					ans += key[str[i]];
				}
			}
			lst = str[i];
		}

		cout << ans << endl;
	}


	return 0;
}