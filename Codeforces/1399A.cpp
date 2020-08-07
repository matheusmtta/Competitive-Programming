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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		vector <int> arr;
		bitset <1000> aux;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			if (!aux[x])
				arr.push_back(x);
			aux[x] = 1;
		}
		sort(arr.begin(), arr.end());
		bool ans = true;
		for (int i = 1; i < arr.size(); i++){
			if (arr[i]-arr[i-1] > 1)
				ans = false;
		}
		ans ? cout << "YES" << endl : cout << "NO" << endl;
	}

	return 0;
}