#include <bits/stdc++.h>

using namespace std;

bool pal(string str){
	int i = 0, j = str.length() - 1;

	while (i < j){
		if (str[i] != str[j]) return false;
		i++; j--;
	}

	return true;
}

int main(){

	int n, count = 1; cin >> n;

	getchar();
	
	while (n--){
		string str, phr; getline(cin, str);

		for (int i = 0; i < str.length(); i++){
			if (str[i] >= 'a' && str[i] <= 'z')
				phr += str[i];
		}

		int size = sqrt(phr.length());

		if (!pal(phr) || size*size != phr.length()) {
			cout << "Case #" << count << ":" << endl;
			cout << "No magic :(" << endl;
			count ++;
			continue;
		}

		cout << "Case #" << count << ":" << endl;
		cout << size << endl;

		count++;
	}

	return 0;
}