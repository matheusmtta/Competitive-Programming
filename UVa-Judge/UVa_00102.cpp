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

bool compare(const pair<string, int> &a, pair<string, int> &b){
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x;

	while (cin >> x){
		vector <int> bins;
		bins.push_back(x);

		//BGC

		map <char, int> mp;

		mp['B'] = 0;
		mp['G'] = 1;
		mp['C'] = 2;

		for (int i = 1; i < 9; i++){
			cin >> x;
			bins.push_back(x);
		}

		string str = "BCG";

		vector <pair<string, int>> ans;

		do {
			ans.push_back(MP(str, 0));
		} while (next_permutation(str.begin(), str.end()));
	
		for (int i = 0; i < ans.size(); i++){
			int tmp = 0;
			for (int j = 0; j < 9; j++){
				int b = j/3;
				int p = mp[ans[i].first[b]];
				if (p != j%3)
					tmp += bins[j];
			}
			ans[i].second = tmp;
		}

		sort(ans.begin(), ans.end(), compare);

		cout << ans[0].first << " " << ans[0].second << endl;
	}

	return 0;
}