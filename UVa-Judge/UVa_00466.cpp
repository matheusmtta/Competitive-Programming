#include <bits/stdc++.h>

using namespace std;

int ans;
int t;
string org[15], fk[15], str;

int find(){
	int k = t-1, l = 0;

	int sum = 0;

	// for (int i = 0; i < t; i++){
	// 	for (int j = 0; j < t; j++)
	// 		cout << fk[i][j];
	// 	cout << endl;
	// }

	// cout << "--------------" << endl;

	for (int i = 0; i < t; i++){
		for (int j = 0; j < t; j++){
			//cout << org[i] << " " << fk[j][k] << endl;
			if (org[i][j] == fk[j][k]) sum++;	
		}
		k--;
	}

	//cout << sum << endl;

	if (sum == t*t) return 1;

	k = t-1; l = t-1; sum = 0;

	for (int i = 0; i < t; i++){
		for (int j = 0; j < t; j++){
			if (org[i][j] == fk[k][l]) sum++;
			l--;
		}
		k--;
		l = t-1;
	}

	if (sum == t*t) return 2;

	k = t-1; sum = 0;

	for (int i = 0; i < t; i++){
		for (int j = 0; j < t; j++){
			//cout << k << endl;
			if (org[i][j] == fk[k][i]) sum++;
			k--;
		}
		k = t-1;
	}

	//cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;

	if (sum == t*t) return 3;

	return -1;
}

int main(){
	int q = 1;
	while (cin >> t){
		cin.ignore();
		for (int i = 0; i < t; i++){
			getline(cin, str);
			for (int j = 0; j < t; j++){
				org[i][j] = str[j];
			}

			int p = 0;

			for (int j = t+1; j < (2*t)+1; j++){
				fk[i][p] = str[j];
				p++;
				//cout << fk[i][j];
			}
			//cout << endl;
		}

		ans = -1;
		
		int sum = 0;

		for (int i = 0; i < t; i++){
			for (int j = 0; j < t; j++){
				if (org[i][j] == fk[i][j]) sum++;
				//cout << fk[i][j];	
			}
			//cout << endl;
		}

		if (sum == t*t) ans = 0; //equal

		if (ans == 0) {cout << "Pattern " << q << " was preserved." << endl; q++; continue;}

		ans = find();

		if (ans == 1) {cout << "Pattern " <<
						q << " was rotated 90 degrees." << endl; q++; continue;}

		if (ans == 2) {cout << "Pattern " <<
						q << " was rotated 180 degrees." << endl; q++; continue;}

		if (ans == 3) {cout << "Pattern " <<
						q << " was rotated 270 degrees." << endl; q++; continue;}			

		string ref[t];

		int k = t-1;

		for (int i = 0; i < t; i++){
			for (int j = 0; j < t; j++){
				ref[i][j] = org[k][j];
			}
			k--;
		}

		sum = 0;

		for (int i = 0; i < t; i++){
			for (int j = 0; j < t; j++){
				if (ref[i][j] == fk[i][j]) sum++;
			}
		}


		if (sum == t*t) {cout << "Pattern " << q << " was reflected vertically." << endl; q++; continue;}

		for (int i = 0; i < t; i++)
			for (int j = 0; j < t; j++)
				org[i][j] = ref[i][j];

		ans = find();

		if (ans == 1) {cout << "Pattern " <<
						q << " was reflected vertically and rotated 90 degrees." << endl; q++; continue;}

		if (ans == 2) {cout << "Pattern " <<
						q << " was reflected vertically and rotated 180 degrees." << endl; q++; continue;}

		if (ans == 3) {cout << "Pattern " <<
						q << " was reflected vertically and rotated 270 degrees." << endl; q++; continue;}


		cout << "Pattern " << q << " was improperly transformed." << endl;

		q++;
	}
}