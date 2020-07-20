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

	int t; cin >> t;

	while (t--){
		vector <int> arr;
		for (int i = 0; i < 3; i++){
			int x; cin >> x;
			arr.push_back(x);
		}
		sort(arr.begin(), arr.end());
		if (arr[0] == arr[1] && arr[1] == arr[2]){
			cout << "YES" << endl;
			for (auto k : arr)
				cout << k << " ";
			cout << endl;
			continue;
		}
		if (arr[0] == arr[1]){
			cout << "NO" << endl;
		}
		else if (arr[1] == arr[2]) {
			cout << "YES" << endl;
			cout << arr[0] << " "
				 << arr[0] << " "
				 << arr[2] << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}	

	return 0;
}