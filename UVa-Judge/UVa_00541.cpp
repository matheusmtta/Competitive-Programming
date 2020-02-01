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
	while(1){
		int n; cin >> n;
		if (n == 0) return 0;
		int arr[n+1][n+1], ans = 1;
		int idx1 = -1, idx2 = -1;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> arr[i][j];

		for (int i = 1; i <= n; i++){
			int sum = 0;
			for (int j = 1; j <= n; j++){
				sum += arr[i][j];
			}
			if (sum%2 == 1) {idx1 = i; break;}
		}

		for (int i = 1; i <= n; i++){
			int sum = 0;
			for (int j = 1; j <= n; j++){
				sum += arr[j][i];
			}
			if (sum%2 == 1) {idx2 = i; break;}
		}

		if (idx1 == -1 && idx2 == -1) {cout << "OK" << endl; continue;}

		arr[idx1][idx2] = !arr[idx1][idx2];

		for (int i = 1; i <= n; i++){
			int sum = 0;
			for (int j = 1; j <= n; j++){
				sum += arr[i][j];
			}
			if (sum%2 == 1) {ans = 0; break;}
		}

		for (int i = 1; i <= n; i++){
			int sum = 0;
			for (int j = 1; j <= n; j++){
				sum += arr[j][i];
			}
			if (sum%2 == 1) {ans = 0; break;}
		}

		if (!ans) cout << "Corrupt" << endl;
		else cout << "Change bit (" << idx1 << "," << idx2 << ")" << endl;
	}

	return 0;
}