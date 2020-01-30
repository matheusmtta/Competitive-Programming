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
	int n; cin >> n;
	while (n--){
		int k; cin >> k;

		int mtx[k][k];

		int vec1[k], vec2[k];

		int mx = -1;

		for (int i = 0; i < k; i++){
			cin >> vec1[i];
			mx = max(mx, vec1[i]);
		}

		for (int i = 0; i < k; i++){
			cin >> vec2[i];
			mx = max(mx, vec2[i]);
		}

		int N, M; N = M = 0;
		vector <int> f1(mx+1, 0), f2(mx+1, 0);

		for (int i = 0; i < k; i++){
			f1[vec1[i]]++;
			f2[vec2[i]]++;
		}

		for (int i = 1; i <= mx; i++){
			N += max(f1[i]*i, f2[i]*i);
		}

		for (int i = 0; i < k; i++){
			for (int j = 0; j < k; j++){
				mtx[i][j] = min(vec1[i], vec2[j]);
				M += mtx[i][j];
			}
		}

		cout << "Matty needs at least " << N << " blocks, and can add at most " << M-N << " extra blocks." << endl; 
	}
	return 0;
}