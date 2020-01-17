#include <bits/stdc++.h>

using namespace std;

bool pal(string str){
	long long i = 0, j = str.length()-1, count = 0;

	while (i < j){
		if (str[i] == str[j]) count++;
		i++; j--;
	}

	return count == str.length()/2;
}

int main(){
	int n; cin >> n;
	while (n--){
		string str; cin >> str;
		int ans = 0;
		string aux = str;
		reverse(str.begin(), str.end());
		string rv = str;
		str = aux;
		long long x, y, z;
		x = stoi(str);
		y = stoi(rv);
		z = x + y;
		str = to_string(z);
		ans++;
		while (1){
			if (pal(str)) break;
			aux = str;
			reverse(str.begin(), str.end());
			rv = str;
			str = aux;
			x, y, z;
			x = stoi(str);
			y = stoi(rv);
			z = x + y;
			str = to_string(z);
			ans++;
		}

		cout << ans << " " << str << endl;
	}

	return 0;
}