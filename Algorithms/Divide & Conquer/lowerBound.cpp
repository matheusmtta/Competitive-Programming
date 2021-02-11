#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
 
typedef long long int int64;
typedef unsigned long long int  uint64;
 
//Lower Bound (greatest element stricly smaller or equal than k)

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, k; cin >> n >> k;
	vector <int> arr(n);
 
	for (int &x : arr)
		cin >> x;
 
	int ans = -INF;
	int l = 0, r = n-1;
	while (l <= r){
		int mid = (l + r) >> 1;
		if (arr[mid] <= k){
			ans = max(mid, ans);
			l = mid+1;
		}
		else
			r = mid-1;
	

	ans == -INF ? cout << 0 << endl : cout << ans+1 << endl;
 
	return 0;
}