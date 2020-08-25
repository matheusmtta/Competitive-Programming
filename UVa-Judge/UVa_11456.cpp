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
		for (auto &x : arr)
			cin >> x;

		reverse(arr.begin(), arr.end());

		vector <int> lis(n, 1), lds(n, 1);

		for (int i = 0; i < n; i++){
			for (int j = 0; j < i; j++){
				if (arr[i] > arr[j])
					lis[i] = max(lis[j]+1, lis[i]);
				if (arr[i] < arr[j])
					lds[i] = max(lds[j]+1, lds[i]);
			}
		}

		int ans = 0;

		for (int i = 0; i < n; i++)
			ans = max(ans, lis[i]+lds[i]-1);

		cout << ans << endl;
	}	

	return 0;
}