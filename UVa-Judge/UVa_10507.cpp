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

	int n, m;

	while (cin >> n){
		cin >> m;
		string str; cin >> str;

		int rs = 3;

		map <int, int> slpt;
		map <int, set <int>> connections;

		for (int i = 0; i < m; i++){
			string s; cin >> s;
			int x = s[0]-'A';
			int y = s[1]-'A';

			slpt[x];
			slpt[y];

			connections[x].insert(y);
			connections[y].insert(x);
		}

		for (int i = 0; i < str.length(); i++)
			slpt[str[i]-'A'] = 1;

		if (slpt.size() < n) {cout << "THIS BRAIN NEVER WAKES UP" << endl; continue;}

		bool change = true;

		int ans = 0;

		map <int, int> temp;

		while (change && rs < n){
			
			temp = slpt;
			change = false;

			for (auto i : connections){
				if (!slpt[i.first]){
					int sum = 0;
					for (auto j : connections[i.first]){
						sum += temp[j];
					}
					if (sum > 2){
						change = true;
						slpt[i.first] = 1;
						rs++;
					}
				}
			}
			ans++;
		}

		if (rs == n) cout << "WAKE UP IN, " << ans << ", YEARS" << endl;
		else cout << "THIS BRAIN NEVER WAKES UP" << endl;
	}

	return 0;
}