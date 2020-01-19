#include <bits/stdc++.h>

using namespace std;

int main(){

	string str, phr;
	vector <string> dict, words;

	while (cin >> str){
		if (str == "XXXXXX") break;
		dict.push_back(str);
	}

	sort(dict.begin(), dict.end());

	while(cin >> phr){
		bool flag = false;

		if (phr == "XXXXXX") break;

		for (int i = 0; i < dict.size(); i++){
			string x1 = phr; 
			string x2 = dict[i];

			sort(x1.begin(), x1.end());
			sort(x2.begin(), x2.end());

			if (x1 == x2){
				flag = true;
				cout << dict[i] << endl;
			}
		}

		if (!flag) cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}

	return 0;
}