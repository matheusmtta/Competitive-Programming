#include <bits/stdc++.h>

using namespace std;

bool comp(char c1, char c2){
    return ::tolower(c1) == ::tolower(c2)?
           c1 < c2 : tolower(c1) < tolower(c2);
}

void permute(string str){
	sort(str.begin(), str.end(), comp);
	
	do {
		cout << str << endl;
	} while(next_permutation(str.begin(), str.end(), comp));
}

int main(){

	int n; cin >> n;

	while (n--){
		
		string str; cin >> str;

		permute(str);
	}
}