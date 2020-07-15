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

	int t, q = 1; cin >> t;

	while (t--){
		set <int> S1, S2;

		int n, m; cin >> n >> m;
		vector <int> graph[110];

		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for (int i = 1; i <= n; i++){
			int s1 = 0, s2 = 0;
			for (int j = 1; j < i; j++){
				if (find(graph[i].begin(), graph[i].end(), j) != graph[i].end()){
					if (S1.find(j) != S1.end()) s1++;
					else s2++;
				}
			}
			if (s1 <= s2) S1.insert(i);
			else S2.insert(i);
		}

		vector <int> ans;

		for (auto k : S1)
			ans.push_back(k);

		cout << "Case #" << q << ": " << ans.size() << endl;
		cout << ans[0];
		for (int i = 1; i < ans.size(); i++)
			cout << ' ' << ans[i];
		cout << endl;
		q++;
	}

	return 0;
}