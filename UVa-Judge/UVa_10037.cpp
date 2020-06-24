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

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back(x);
		}

		sort(arr.begin(), arr.end());

		vector <pair <int, int>> rsp;

		int ans = 0;

		if (arr.size() == 1){
			cout << arr[0] << endl;
			cout << arr[0] << endl;
			cout << endl;
			continue;
		}
		else if (arr.size() == 2){
			cout << max(arr[0], arr[1]) << endl;
			cout << arr[0] << " " << arr[1] << endl;
			cout << endl;
			continue;
		}
		else {
			queue <int> q;
			int a = arr[0];
			int b = arr[1];
			for (int i = arr.size()-1; i >= 2; i--)
				q.push(arr[i]);

			while (!q.empty()){
				if (q.size() >= 2){
					int c = q.front();
					q.pop();
					int d = q.front();
					q.pop();
					int cen1 = b + a + c + b; 
					int cen2 = c + a + d + a;
					ans += min(cen1, cen2);
					if (cen1 > cen2){
						rsp.push_back({a, c});
						rsp.push_back({a, -1});
						rsp.push_back({a, d});
						rsp.push_back({a, -1});
					}
					else {
						rsp.push_back({a, b});
						rsp.push_back({a, -1});
						rsp.push_back({d, c});
						rsp.push_back({b, -1});
					}
					if (q.empty()){
						rsp.push_back({a, b});
						ans += b;
					}
				}
				else {
					int c = q.front();
					q.pop();
					ans += c + a + b;
					rsp.push_back({a, c});
					rsp.push_back({a, -1});
					rsp.push_back({a, b});
				}
			}
		}

		cout << ans << endl;
		for (auto k : rsp){
			if (k.second == -1)
				cout << k.first << endl;
			else
				cout << k.first << " " << k.second << endl;
		}

		cout << endl;
	}

	return 0;
}