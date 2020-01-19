#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	cin.ignore();
	cin.ignore();

	while (n--){
		string str;
		vector <string> words;

		while (getline(cin, str) && str != ""){
            words.push_back(str);
		}

        sort(words.begin(), words.end());

        for (int i = 0; i < words.size(); i++){
        	for (int j = i+1; j < words.size(); j++){
        		string x1; x1 = words[i];
        		string x2; x2 = words[j];


        		string s, l;

        		for (int k = 0; k < x1.length(); k++){
        			if (x1[k] != ' ') s += x1[k];
        		}

        		for (int k = 0; k < x2.length(); k++){
        			if (x2[k] != ' ') l += x2[k];
        		}

        		sort(s.begin(), s.end());
        		sort(l.begin(), l.end());

        		if (s == l)
        			cout << words[i] << " = " << words[j] << endl;
        	}
        }

        if (n) cout << endl;
	}
}