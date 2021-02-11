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

//Upper Bound (smallest element strictly greater or equal than k)
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, k; cin >> n >> k;
	vector <int> arr(n);
 
	for (int &x : arr)
		cin >> x;
	
	int l = 0, r = n-1;
	int ans = INF;

	while (l <= r){
		int mid = (l+r)>>1;
		if (arr[mid] >= k){
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}

	ans == INF ? cout << n+1 << endl : cout << ans+1 << endl;

	return 0;
}