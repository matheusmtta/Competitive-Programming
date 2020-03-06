#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

string mtx[10][3];

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	mtx[1][0] = "*.";
	mtx[1][1] = "..";
	mtx[1][2] = "..";

	mtx[2][0] = "*.";
	mtx[2][1] = "*.";
	mtx[2][2] = "..";

	mtx[3][0] = "**";
	mtx[3][1] = "..";
	mtx[3][2] = "..";

	mtx[4][0] = "**";
	mtx[4][1] = ".*";
	mtx[4][2] = "..";

	mtx[5][0] = "*.";
	mtx[5][1] = ".*";
	mtx[5][2] = "..";

	mtx[6][0] = "**";
	mtx[6][1] = "*.";
	mtx[6][2] = "..";

	mtx[7][0] = "**";
	mtx[7][1] = "**";
	mtx[7][2] = "..";

	mtx[8][0] = "*.";
	mtx[8][1] = "**";
	mtx[8][2] = "..";

	mtx[9][0] = ".*";
	mtx[9][1] = "*.";
	mtx[9][2] = "..";

	mtx[0][0] = ".*";
	mtx[0][1] = "**";
	mtx[0][2] = "..";

	map <vector <string>, int> rev;

	for (int i = 0; i < 10; i++){
		vector <string> tmp;
		for (int j = 0; j < 3; j++){
			tmp.push_back(mtx[i][j]);
		}
		rev[tmp] = i;
	}


	while (true){
		int t; cin >> t;
		if (t == 0) exit(0);

		char cmd; cin >> cmd;

		if (cmd == 'S'){
			string str; cin >> str;
			for (int j = 0; j < 3; j++){
				for (int i = 0; i < str.length(); i++){
					int num = str[i] - '0';
					cout << mtx[num][j];
					if (i+1 != str.length()) cout << " ";
				}
				cout << endl;
			}
		}
		else {
			vector <string> arr[t];
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < t; j++){
					string aux; cin >> aux;
					arr[j].push_back(aux);
				}
			}
			for (int i = 0; i < t; i++){
				cout << rev[arr[i]];
			}
			cout << endl;
		}
	}

	return 0;
}