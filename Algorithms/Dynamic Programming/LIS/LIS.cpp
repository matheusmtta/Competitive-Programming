#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int n;
vector <int> arr;
vector <int> ans;

int upper_bound(int x){
	int l = 0, r = n, ub, idx;

	while (l <= r){
		int mid = (l+r)/2;
		if (ans[mid] < x)
			l = mid + 1;
		else {
			ub = ans[mid];
			idx = mid;
			r = mid - 1;
		}
	}

	return idx;
}

int LIS(){
	ans.resize(n+1);

	for (auto &x : ans) x = INF;
	
	ans[0] = -INF;

	for (int i = 0; i < n; i++){
		int pos = upper_bound(arr[i]);
		if (ans[pos-1] < arr[i] && arr[i] < ans[pos])
			ans[pos] = arr[i];
	}

	int rsp = n;

	while (ans[rsp] == INF){
		rsp--;
	}

	return rsp;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	arr.resize(n);

	for (auto &x: arr)
		cin >> x;

	cout << LIS() << endl;

	return 0;
}