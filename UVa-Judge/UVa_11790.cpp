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

	int t, q = 1; cin >> t;
	while (t--){
		int n; cin >> n;

		vector <pair<int, int>> arr;
		
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back({x, -1});
		}

		for (int i = 0; i < n; i++)
			cin >> arr[i].second;

		vector <int> lis(n), lds(n);

		for (int i = 0; i < n; i++){
			lis[i] = arr[i].second;
			lds[i] = arr[i].second;
			for (int j = 0; j < n; j++){
				if (arr[i].first > arr[j].first){
					lis[i] = max(lis[i], lis[j]+arr[i].second);
				}
				if (arr[i].first < arr[j].first){
					lds[i] = max(lds[i], lds[j]+arr[i].second);
				}
			}
		}

		int clis=0, clds=0;

		for (int i = 0; i < n; i++){
			clis = max(lis[i], clis);
			clds = max(lds[i], clds);
		}

		cout << "Case " << q++ << ". ";
		if (clis >= clds)
			cout << "Increasing (" << clis << "). Decreasing (" << clds << ")." << endl;
		else
			cout << "Decreasing (" << clds << "). Increasing (" << clis << ")." << endl;
	}	

	return 0;
}