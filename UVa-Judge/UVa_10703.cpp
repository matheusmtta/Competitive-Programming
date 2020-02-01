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

int main(){
	while (1){
		int w, h, n;
		cin >> w >> h >> n;

		if (w == 0 && h == 0 && n == 0) return 0;

		int mtx[505][505];

		for (int i = 0; i <= 500; i++)
			for (int j = 0; j <= 500; j++)
				mtx[i][j] = 1;

		for (int k = 0; k < n; k++){
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);

			for (int i = y1; i <= y2; i++){
				for (int j = x1; j <= x2; j++){
					mtx[i][j] = 0;
				}
			}
		}

		int sum = 0;

		for (int i = 1; i <= h; i++){
			for (int j = 1; j <= w; j++){
				sum += mtx[i][j];
			}
		}

		if (sum == 0) cout << "There is no empty spots." << endl;
		else if (sum == 1) cout << "There is one empty spot." << endl;
		else cout << "There are " << sum << " empty spots." << endl;
	}

	return 0;
}