#include <bits/stdc++.h>

using namespace std;

string str;

int cps(){
	int l = str.length();
	int dp[l][l];

	map <string, bool> find;

	for (int i = 0; i < str.length(); i++){
		dp[i][i] = 1;
		find[string(str.begin() + i, str.begin() + i + 1)] = true;
	}

	for (int k = 0; k < l-1; k++){
		if (str[k] == str[k+1]){
			dp[k][k+1] = 1;
			find[string(str.begin() + k, str.begin() + k + 2)] = true;
		}

		else {
			dp[k][k+1] = 0;
		}
	}

	for (int s = 3; s <= l; s++){
		for (int b = 0; b <= l - s; b++){
			int end = b + s - 1;

			if (str[b] == str[end] && dp[b + 1][end -1]){
				dp[b][end] = 1;
				find[string(str.begin() + b, str.begin() + end + 1)] = true;
			}

			else
				dp[b][end] = 0;
		}
	}

	return find.size();
}

int main(){

	while(cin >> str){
		cout << "The string '" << str <<  "' contains " << cps() << " palindromes." << endl;
	}

	return 0;
}