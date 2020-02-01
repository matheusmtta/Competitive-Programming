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

int xmv[4] = {0, -1, 0, 1};
int ymv[4] = {1, 0, -1, 0};


bool ok(int i, int j){
	if (i < 0 || i >= 3) return 0;
	if (j < 0 || j >= 3) return 0;
	return 1;
}

int main(){
	int t; cin >> t;
	while (t--){
		getchar();
		char x;
		int mtx[3][3];
		int nmtx[3][3];

		int k = 0;

		bool ans = false;

		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cin >> x;
				mtx[i][j] = x - '0';
				nmtx[i][j] = mtx[i][j];
				if (mtx[i][j]) ans = true;
			}
		}

		if (!ans) {cout << -1 << endl; continue;}

		ans = true;

		while (1){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					if (mtx[i][j] != 0) ans = false;
				}
			}

			if (ans) break;
			ans = true;
			k++;
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					int sum = 0;
					for (int k = 0; k < 4; k++){
						int aux1 = j + xmv[k];
						int aux2 = i + ymv[k];
						if (ok(aux1, aux2)){
							sum += mtx[aux2][aux1];
						}
						nmtx[i][j] = sum%2;
					}
				}
			}

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					mtx[i][j] = nmtx[i][j];
		}

		cout << k-1 << endl;
	}

	return 0;
}