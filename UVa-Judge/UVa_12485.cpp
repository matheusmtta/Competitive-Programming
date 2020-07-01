#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while (cin >> n){
		vector <int> arr;
		int64 sum = 0;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back(x);
			sum += arr[i];
		}
		if (sum%n != 0){
			cout << -1 << endl;
			continue;
		}
		sort(arr.begin(), arr.end());
		
		sum/=n;
		int64 ans = 1;
		
		int i = 0, j = n-1;
		
		while (i < j){
			if (arr[i] < sum && arr[j] > sum){
				int diff = min(abs(arr[i] - sum), abs(arr[j] - sum));
				arr[i] += diff;
				arr[j] -= diff;
				ans += diff;
			}
			if (arr[i] == sum) i++;
			if (arr[j] == sum) j--;
		}

		cout << ans << endl;
	}

	return 0;
}