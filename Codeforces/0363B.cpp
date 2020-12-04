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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;
	
	vector <int> arr(n+1);
	
	arr[0] = 0;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		arr[i] = arr[i-1] + x;
	}

	int ans = INF, pos = -1;

	for (int i = 1; i <= n-k+1; i++){
		if (arr[i+k-1]-arr[i-1] < ans){
			ans = arr[i+k-1]-arr[i-1];
			pos = i;
		}
	}

	cout << pos << endl;

	return 0;
}