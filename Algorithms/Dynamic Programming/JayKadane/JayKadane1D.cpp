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

//Maximum 1D Range Sum O(n)
int MaxRangeSum1D(){
 	int n; cin >> n;
 	vector <int> arr;

 	int ans = -INF, sum = 0;

 	for (int i = 0; i < n; i++){
 		int x; cin >> x;
 		arr.push_back(x);
 	}

 	for (int i = 0; i < n; i++){
 		sum += arr[i];
 		ans = max(sum, ans);
 		if (sum < 0) sum = 0;
 	}

 	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	MaxRangeSum2D();

	return 0;
}