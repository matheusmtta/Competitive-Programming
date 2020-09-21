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

	int t; cin >> t;

	while (t--){
		int obj; cin >> obj;
		int n; cin >> n;
		vector <int> arr(n);

		for (auto &x : arr)
			cin >> x;

		int memo[10010];

		memset(memo, INF, sizeof memo);

		memo[0] = 0;

		for (int i = 1; i <= 10000; i++)
			for (int j = 0; j < n; j++)
				if (i >= arr[j])
					memo[i] = min(memo[i - arr[j]] + 1, memo[i]);
		//for (int i = 0; i < n; i++){
		//	for (int j = 10000; j - arr[i] >= 0; j--){
		//		memo[j] = min(memo[j - arr[i]] + 1, memo[j]);
		//	}
		//}

		for (int i = obj; i <= 10000; i++){
			if (memo[i] < INF){
				cout << i << " " << memo[i] << endl;
				break;
			}
		}
	}

	return 0;
}