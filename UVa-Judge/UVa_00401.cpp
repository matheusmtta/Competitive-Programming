#include <bits/stdc++.h>

using namespace std;


int main(){
	string str;

	vector <pair <char, char> > mirror;

	mirror.push_back(make_pair('A', 'A'));
	mirror.push_back(make_pair('E', '3'));
	mirror.push_back(make_pair('3', 'E'));
	mirror.push_back(make_pair('H', 'H'));
	mirror.push_back(make_pair('I', 'I'));
	mirror.push_back(make_pair('J', 'L'));
	mirror.push_back(make_pair('L', 'J'));
	mirror.push_back(make_pair('M', 'M'));
	mirror.push_back(make_pair('O', 'O'));
	mirror.push_back(make_pair('S', '2'));
	mirror.push_back(make_pair('2', 'S'));
	mirror.push_back(make_pair('T', 'T'));
	mirror.push_back(make_pair('U', 'U'));
	mirror.push_back(make_pair('V', 'V'));
	mirror.push_back(make_pair('W', 'W'));
	mirror.push_back(make_pair('X', 'X'));
	mirror.push_back(make_pair('Y', 'Y'));
	mirror.push_back(make_pair('Z', '5'));
	mirror.push_back(make_pair('5', 'Z'));
	mirror.push_back(make_pair('8', '8'));
	mirror.push_back(make_pair('1', '1'));

	while (cin >> str){
		bool isPal = false;
		bool isRev = false;
		int countP = 0, countR = 0;

		int i = 0, j = str.length()-1;

		while (i < j){
			if (str[i] == str[j]) countP++;
			for (int k = 0; k < mirror.size(); k++){
				if (str[i] == mirror[k].first && str[j] == mirror[k].second)
					countR++;
			}

			i++; j--;
		}

		if (countP == floor(str.length()/2)) isPal = true;
		if (countR == floor(str.length()/2)) {
			if (str.length()%2 == 0) isRev = true;
			else {
				for (int k = 0; k < mirror.size(); k++){
					if (str[str.length()/2] == mirror[k].first && str[str.length()/2] == mirror[k].second)
						isRev = true;
				}
			}
		}

		int ans = 0;

		if (str.length() == 1) {
			for (int k = 0; k < mirror.size(); k++){
				if (str[0] == mirror[k].first && str[0] == mirror[k].second)
					ans = 1;
			}
			if (!ans) cout << str << " -- is a regular palindrome." << endl;
			else cout << str << " -- is a mirrored palindrome." << endl;
		}
		else if (isPal && isRev) cout << str << " -- is a mirrored palindrome." << endl;
		else if (isPal && !isRev) cout << str << " -- is a regular palindrome." << endl;
		else if (!isPal && isRev) cout << str << " -- is a mirrored string." << endl;
		else cout << str << " -- is not a palindrome." << endl;
		cout << endl;
	}
}