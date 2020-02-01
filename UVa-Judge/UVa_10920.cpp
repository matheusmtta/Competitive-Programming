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
		int n, p; cin >> n >> p;
		if (n == 0 && p == 0) return 0;
		int move = 0;
		//0 ----> up
		//1 ----> down
		//2 ----> left
		//3 ----> right
		int count = 0;
		int step = 1, pos = 1;
		int x = ceil((1.0*n)/2), y = ceil((1.0*n)/2);

		int xmv[4] = {0, -1, 0, 1};
		int ymv[4] = {1, 0, -1, 0};

		int idx = 0;

		while (pos != p){
			if (count%2 == 0 && count != 0)
				step++;

			if (pos + step > p){
				int aux = p - pos;

				x += (aux*xmv[idx%4]);
				y += (aux*ymv[idx%4]);

				break;				
			}

			x += (step*xmv[idx%4]);
			y += (step*ymv[idx%4]);

			pos += step;
			
			count++;
			idx++;
		}

		cout << "Line = " << y << ", column = " << x << "." << endl;
	}

	return 0;
}