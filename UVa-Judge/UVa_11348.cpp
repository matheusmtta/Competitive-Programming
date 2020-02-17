#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
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

	int q = 1;

	while (t--){
		int n; cin >> n;

		map <int, int> mp;
		vector <int> person[n];

		for (int i = 0; i < n; i++){
			int m; cin >> m;

			for (int j = 0; j < m; j++){
				int tmp; cin >> tmp;
				if (find(person[i].begin(), person[i].end(), tmp) == person[i].end()){
					mp[tmp]++;
					person[i].push_back(tmp);
				}
			}
		}

		int uniq = 0;

		for (auto i : mp){
			if (i.second == 1)
				uniq++;
		}

		int sum;

		printf("Case %d:", q);

		for (int i = 0; i < n; i++){
			sum = 0;
			for (int j = 0; j < person[i].size(); j++){
				if (mp[person[i][j]] == 1)
					sum++;
			}

			double ans;

			ans = ((sum*1.0)/(uniq*1.0))*100;

			printf(" %.6lf%c", ans, '%');
		}
		printf("\n");
		q++;
	}

	return 0;
}