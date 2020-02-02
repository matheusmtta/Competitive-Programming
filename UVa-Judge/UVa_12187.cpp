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

int N, R, C, K;
int xmv[4] = {0, -1, 0, 1};
int ymv[4] = {1, 0, -1, 0};

bool ok(int i, int j){
	if (i < 0 || i >= R) return false;
	else if (j < 0 || j >= C) return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true){
		cin >> N >> R >> C >> K;
		if (!(N || R || K || C)) return 0;

		int mtx[R][C], aux[R][C];

		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++){
				cin >> mtx[i][j];
				aux[i][j] = mtx[i][j];
			}
		}

		while (K--){
			for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					for (int k = 0; k < 4; k++){
						int x = (mtx[i][j] + 1)%N;
						if (ok(i + ymv[k], j + xmv[k]) &&
							mtx[i + ymv[k]][j + xmv[k]] == x){
							aux[i + ymv[k]][j + xmv[k]] = mtx[i][j];
						}
					}
				}
			}

			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++)
					mtx[i][j] = aux[i][j];
		}

		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++){
				cout << mtx[i][j];
				if (j != C-1) cout << " ";
			}
			cout << endl;
		}
	}	

	return 0;
}