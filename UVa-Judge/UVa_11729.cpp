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

vector <pair<int, int>> arr;

bool comp(const pair<int, int> &a, const pair<int, int> &b){
	return a.second > b.second;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q = 1;

	while (cin >> n){
		if (n == 0) return 0;
		for (int i = 0; i < n; i++){
			int x, y; cin >> x >> y;
			arr.push_back({x, y});
		}

		sort(arr.begin(), arr.end(), comp);

		int ans = 0, tot = 0;

		for (int i = 0; i < arr.size(); i++){
			tot += arr[i].first;
			ans = max(tot + arr[i].second, ans);
		}

		cout << "Case " << q << ": ";
		cout << ans << endl;
		q++;
		arr.clear();
	}

	return 0;
}