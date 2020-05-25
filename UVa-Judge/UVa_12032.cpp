#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> arr;

bool solve(int x){
	int lst = 0;

	for (int i = 0; i < arr.size(); i++){
		if (arr[i] - lst > x) return false;
		if (arr[i] - lst == x) x--;
		lst = arr[i];
	}
	return true;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	int q = 1;

	while (t--){
		int n; cin >> n;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back(x);
		}

		int64 l = 1, r = 10000010, ans = INF;

		while (l <= r){
			int64 mid = (l + r)/2;
			
			if (solve(mid)){
				ans = min(mid, ans);
				r = mid - 1;
			}
			else l = mid + 1;
		}

		cout << "Case " << q << ": " << ans << endl;

		arr.clear();
		q++;
	}

	return 0;
}