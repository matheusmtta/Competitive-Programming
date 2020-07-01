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

	int n, m;

	while (cin >> n >> m){
		if (n == 0 && m == 0) return 0;
		vector <int> d, k;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			d.push_back(x);
		}
		for (int i = 0; i < m; i++){
			int x; cin >> x;
			k.push_back(x);
		}

		sort(k.begin(), k.end());
		sort(d.begin(), d.end());

		int lst = 0, dest = 0;
		int ans = 0;

		for (int i = 0; i < n; i++){
			while (lst < m){
				if (d[i] <= k[lst]){
					ans += k[lst];
					lst++;
					dest++;
					break;
				}
				lst++;
			}
		}

		dest == n ? cout << ans << endl : cout << "Loowater is doomed!" << endl;
	}

	return 0;
}