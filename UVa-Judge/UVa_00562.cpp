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
		int n; cin >> n;
		vector <int> arr(n);

		int sum = 0;

		for (auto &x : arr){
			cin >> x;
			sum += x;
		}

		int avg = sum/2;

		vector <int> memo(101000, 0);

		for (int i = 0; i < n; i++){
			for (int j = avg; j >= arr[i]; j--){
				memo[j] = max(memo[j], memo[j - arr[i]] + arr[i]);
			}
		}

		cout << sum-2*memo[avg] << endl;
	}

	return 0;
}