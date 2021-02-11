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

//Search for N in a array
//Time complexity: O(logN)

int N;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector <int> arr(n);

	for (int &x : arr)
		cin >> x;

	int ans, k; cin >> k;

	int l = 0, r = arr.size()-1, flag = 0;

	while (l <= r && !flag){
		int mid = l+r/2;
		if (arr[mid] == k){
			ans = mid, flag = true;
		}
		else if (arr[mid] < k) 
			l = mid + 1;
		else
			r = mid - 1;
	}

	flag ? cout << ans << endl : cout << "DOES NOT EXIST" << endl;

	return 0;
}