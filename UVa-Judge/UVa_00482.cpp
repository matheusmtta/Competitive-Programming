#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string line;
	getline(cin, line);
	while (n--){
		getline(cin, line);
		getline(cin, line);
		stringstream sin(line);

		int idx[10000];
		string arr[10000];

		int x = 1;

		string str, phr;

        sin << str;
        while(sin >> idx[x])
            x++;

		for (int i = 1; i < x; i++){
			string y; cin >> y;
			arr[idx[i]] = y;
		}

		for (int i = 1; i < x; i++)
			cout << arr[i] << endl;

		if(n) {
			getline(cin, line);
			cout << endl;
		}
	}
}