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
		vector <pair<int64, int64>> arr;
		int64 c = LINF, o = LINF;
		for (int i = 0; i < n; i++){
			int64 x; cin >> x;
			arr.push_back({x, 0});
			c = min(x, c);
		}
		for (int i = 0; i < n; i++){
			int64 x; cin >> x;
			arr[i].second = x;
			o = min(x, o);
		}

		int64 ans = 0;
		
		for (int i = 0; i < arr.size(); i++){
			if (arr[i].first > c && arr[i].second > o){
				int64 aux = min(arr[i].first-c, arr[i].second-o);
				arr[i].first-=aux;
				arr[i].second-=aux;
				ans += aux;
			}
			if (arr[i].first > c){
				ans += arr[i].first - c;
				arr[i].first -= c;
			}
			if (arr[i].second > o){
				ans += arr[i].second - o;
				arr[i].second -= o;
			}
		}

		cout << ans << endl;
	}

	return 0;
}