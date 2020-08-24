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

	int n;
	while (cin >> n){
		vector <pair<int, int>> arr;
		for (int i = 0; i < n; i++){
			int x, y; cin >> x >> y;
			arr.push_back({x, y});
		}

		sort(arr.begin(), arr.end());
		vector <int> dt(n, 1);
		vector <int> db(n, 1);

		for (int i = 0; i < n; i++){
			for (int j = 0; j < i; j++){
				if (arr[i].first > arr[j].first && arr[i].second == arr[j].second+2)
					dt[i] = max(dt[i], db[j]+1);	
				if (arr[i].first > arr[j].first && arr[i].second == arr[j].second-2)
					db[i] = max(db[i], dt[j]+1);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max({ans, dt[i], db[i]});
		cout << ans << endl;
	}

	return 0;
}