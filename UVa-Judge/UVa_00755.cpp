#include <bits/stdc++.h>

using namespace std;

char key[100];


int main(){
	int n; cin >> n;
	getchar();

	key['0'] = '0';
	key['1'] = '1';
	key['A'] = key['B'] = key['C'] = key['2'] = '2';
	key['D'] = key['E'] = key['F'] = key['3'] = '3';
	key['G'] = key['H'] = key['I'] = key['4'] = '4';
	key['J'] = key['K'] = key['L'] = key['5'] = '5';
	key['M'] = key['N'] = key['O'] = key['6'] = '6';
	key['P'] = key['R'] = key['S'] = key['7'] = '7';
	key['T'] = key['U'] = key['V'] = key['8'] = '8';
	key['W'] = key['X'] = key['Y'] = key['9'] = '9';

	while(n--){
		int c; cin >> c;

		map <string, int> numbers;

		for (int i = 0; i < c; i++){
			string m; cin >> m;
			string phr;
			for (int j = 0; j < m.length(); j++){
				if (!(m[j] == 'Q' || m[j] == 'Z' || m[j] == '-'))
					phr += key[m[j]];
				if (phr.length() == 3) phr += '-';
			}

			if (numbers.count(phr))
				numbers[phr] += 1;
			else
				numbers.insert({phr, 1});
		}

		map<string, int>::iterator itr; 

		int q = 0;

		for (itr = numbers.begin(); itr != numbers.end(); itr++){
			if (itr->second > 1) {cout << itr->first << " " << itr->second << endl; q++;}
		}

		if (!q) cout << "No duplicates." << endl;

		if (n) cout << endl;
	}
}