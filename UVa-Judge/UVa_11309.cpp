#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	while (n--){
		string str; cin >> str;

		str.erase(str.begin() + 2);
		
		string x1, x2;
		int h, m;

		x1 = str.substr(0, 2);
		x2 = str.substr(2, 3);
		h = stoi(x1);
		m = stoi(x2);

		m = (m + 1)%60;
		if (m == 0)
			h = (h + 1)%24;

		while (1){
			if (h == 0){
				if (m <= 9) {
					cout << "00:0" << m << endl;
					break;
				}

				else if (m%10 == m/10){
					cout << "00:" << m << endl;
					break;
				}
			}

			else if (h != 0 && h <= 9){
				if (h == m%10){
					cout << "0" << h << ":";
					if (m <= 9)
						cout << "0" << m << endl;
					else
						cout << m << endl;
					break;
				}
			}

			else {
				if (h/10 == m%10 && h%10 == m/10){
					if (h <= 9)
						cout << "0" << h << ":";
					else 
						cout << h << ":";
					if (m <= 9)
						cout << "0" << m << endl;
					else
						cout << m << endl;
					break;
				}
			}

			m = (m + 1)%60;
			if (m == 0)
				h = (h + 1)%24;
		}
	}
}