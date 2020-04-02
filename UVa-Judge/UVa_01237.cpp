#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		vector <pair<string, pair<int, int>>> arr;

		for (int i = 0; i < n; i++){
			string str; int x, y;
			cin >> str >> x >> y;
			arr.push_back(MP(str, MP(x, y)));
		}

		int q; cin >> q;

		int ans = -1;
		bool flag = false;

		for (int i = 0; i < q; i++){
			int p; cin >> p;
			flag = false, ans = -1;
			for (int j = 0; j < n; j++){
				if (p >= arr[j].second.first &&
					p <= arr[j].second.second){
					if (!flag){
						flag = true;
						ans = j;
						continue;
					}
					else{
						ans = -1;
						break;
					}
				}
			}
			ans != -1 ? cout << arr[ans].first << endl :
						cout << "UNDETERMINED" << endl;
		}
		if (t) cout << endl;
	}

	return 0;
}