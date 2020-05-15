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

int n, m;
vector <int> arr;

bool solve(int x){
	int k = 0, curr = 0;

	for (int i = 0; i < n; i++){
		if (arr[i] > x) return false;
		if (curr + arr[i] > x){
			k++;
			curr = 0;
		}
		curr += arr[i];
	}

	if (curr > x) return false;
	if (curr != 0) k++;

	if (k <= m) return true;
	return false;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> m){
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back(x);
		}

		int64 l = 1, r = 1000000000, ans = INF;

		while (l <= r){
			int64 x = (l+r)/2;
			if (solve(x)){
				ans = min(x, ans);
				r = x-1;
			}
			else
				l = x+1;
		}

		cout << ans << endl;

		arr.clear();
	}
	
	return 0;
}