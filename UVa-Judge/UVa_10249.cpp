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

bool comp (const pair<int, int> &a, const pair<int, int> &b){
	return a.first > b.first;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	while (cin >> m >> n){
		if (m == 0 && n == 0) return 0;
		vector <int> teams, aux;
		vector <pair<int, int>> tables;

		int mx = -1;
		
		for (int i = 0; i < m; i++){
			int x; cin >> x;
			teams.push_back(x);
			mx = max(x, mx);
		}

		int mx2 = -1;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			tables.push_back({x, i+1});
			mx2 = max(mx2, x);
		}

		if (mx > n || m > mx2) {cout << 0 << endl; continue;}

		map <pair<int, int>, int> mp;

		bool ans = true;

		for (int i = 0; i < teams.size(); i++){
			sort(tables.begin(), tables.end(), comp);
			for (int j = 0; j < teams[i]; j++){
				mp[{i, j}] = tables[j].second;
				tables[j].first--;
				if (tables[j].first < 0) ans = false;
			}
			if (!ans) break;
		}

		if (!ans) {cout << 0 << endl; continue;}
		cout << 1 << endl;
		for (int i = 0; i < teams.size(); i++){
			for (int j = 0; j < teams[i]; j++){
				cout << mp[{i, j}];
				if (j != teams[i]-1) cout << " ";
			}
			cout << endl;
		}
	}

	return 0;
}