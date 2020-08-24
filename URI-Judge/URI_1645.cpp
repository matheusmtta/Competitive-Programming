#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; 
	while (cin >> n >> k){
		if (n == 0 && k == 0) exit(0);

		vector <int> arr(n);

		for (auto &x : arr)
			cin >> x;

		int64 memo[200][200];

		memset(memo, 0, sizeof memo);

		int64 ans = 0;

		for (int i = 0; i < n; i++){
			memo[i][0] = 1;
			for (int j = 0; j < i; j++){
				if (arr[i] > arr[j]){
					for (int s = 0; s < i; s++){
						memo[i][s+1] += memo[j][s]; 
					}
				}
			}
			ans += memo[i][k-1];
		}

		int sum = 0;

		//for (int i = 0; i < n; i++)
		//	for (int j = 0; j < n; j++)
		//		sum += memo[i][j];

		//cout << sum << endl;
		cout << ans << endl;
	}

	return 0;
}