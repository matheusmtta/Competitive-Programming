#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y, n; 
	while (cin >> x >> y >> n){
		vector <int> arr(n+1, -1);
		int lst = 0;

		arr[0] = 0;

		for (int i = 1; i <= n; i++){
			if (i - x >= 0 && arr[i - x] != -1)
				arr[i] = max(arr[i-x]+1, arr[i]);
			if (i - y >= 0 && arr[i - y] != -1)
				arr[i] = max(arr[i], arr[i-y]+1);
			if (arr[i] != -1)
				lst = i;
		}

		lst == n ? cout << arr[lst] << endl : cout << arr[lst] << " " << n - lst << endl;
	}	

	return 0;
}