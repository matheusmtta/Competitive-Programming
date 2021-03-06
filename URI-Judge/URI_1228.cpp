#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; 
	while (cin >> n){
		if (n == 0) break;
		map <int, int> mp;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			mp[x] = i+1;
		}

		vector <int> arr;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back(mp[x]);
		}

		int ans = 0;

		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++){
				if (arr[i] > arr[j]){
					ans++;
					swap(arr[i], arr[j]);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}