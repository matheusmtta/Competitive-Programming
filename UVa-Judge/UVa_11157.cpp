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
	int q = 1;

	while (t--){
		int64 n, sz; cin >> n >> sz;
		vector <pair<int64, pair<char, int>>> arr;
		arr.push_back({sz, {'B', 0}});
		arr.push_back({0, {'B',0}});
		for (int i = 0; i < n; i++){
			char k, aux;
			cin >> k >> aux;
			int64 x; cin >> x;
			arr.push_back({x, {k, 0}});
		}
		sort(arr.begin(), arr.end());

		int64 ans = -1;
		pair<int64, pair<char, int>> curr = {0,{'B',0}};

		bool flag = 0;

		for (int i = 1; i <= n+1; i++){
			if (arr[i].first <= curr.first) continue;
			if (arr[i].second.first == 'B'){
				ans = max(abs(arr[i].first-curr.first), ans);
				curr = arr[i];
				flag = 0;
			}
			else {
				if (flag) {
					flag = 0;
					continue;
				} //alternating small stones
				ans = max(abs(arr[i].first-curr.first), ans);
				curr = arr[i];
				arr[i].second.second = 1;
				flag = 1;
			}
		}

		reverse(arr.begin(), arr.end());
		curr = {sz, {'B', 0}};

		for (int i = 1; i <= n+1; i++){
			if (arr[i].first >= curr.first || arr[i].second.second == 1) 
				continue;
			ans = max(ans, abs(arr[i].first-curr.first));
			curr = arr[i];
		}

		cout << "Case " << q++ << ": " << ans << endl;
	}

	return 0;
}