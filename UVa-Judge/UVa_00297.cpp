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

const int sz = 32;
char cmd;

int grid[sz][sz];

void paint(char cmd, int d1, int d2, int s){
	cin >> cmd;
	if (cmd == 'p'){
		int tam = s/2;
		paint(cmd, d1+tam, d2, tam);
		paint(cmd, d1, d2, tam);
		paint(cmd, d1, d2+tam, tam);
		paint(cmd, d1+tam, d2+tam, tam);
	}
	else if (cmd == 'f'){
		for (int i = d1; i < (d1+s); i++){
			for (int j = d2; j < (d2+s); j++){
				grid[i][j] = 1;
			}
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){

		for (int i = 0; i < 32; i++){
			for (int j = 0; j < 32; j++){
				grid[i][j] = 0;
			}
		}


		int ans = 0;
		
		paint(cmd, 0, 0, 32); //img1, position, d1(row), d2(colunm), sz
		paint(cmd, 0, 0, 32); //img2, position, d1(row), d2(colunm), sz

		for (int i = 0; i < 32; i++){
			for (int j = 0; j < 32; j++){
				if (grid[i][j]) ans++;
			}
		}

		cout << "There are " << ans << " black pixels." << endl;
	}

	return 0;
}