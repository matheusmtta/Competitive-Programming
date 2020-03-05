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

bool compare(const int &a, const int &b){
	return a > b;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true){
		int n, m; cin >> m >> n;

		n *= 100;
		m *= 100;

		if (n == 0 && m == 0) exit(0);

		int l; cin >> l;
		int k; cin >> k;

		vector <int> a(k);
		map <int, int> mp;

		for (int i = 0; i < k; i++){
			cin >> a[i];
			a[i] *= 100;
			mp[a[i]] += 1;
		}

		sort(a.begin(), a.end(), compare);

		map <int, int> tmp = mp;

		int ans = INF;

		if (n % l == 0){
			int need = n/l;
			int covered = 0;
			int count = 0;
			for (int i = 0; i < k; i++){
				if (covered == need) break;
				if (mp[a[i]] > 0){
					if (a[i] == m){
						mp[a[i]]--;
						covered++;
						count++;
					}
					else if (a[i] < m){
						if (mp[m - a[i]] > 0){
							if (a[i] == m-a[i] && mp[a[i]] < 2) continue;
							mp[m - a[i]]--;
							mp[a[i]]--;
							covered++;
							count += 2;
						}
					}
				}
			}
			if (covered == need){
				ans = min(ans, count);
			}
		}

		mp = tmp;

		if (m % l == 0){
			int need = m/l;
			int covered = 0;
			int count = 0;
			for (int i = 0; i < k; i++){
				if (covered == need) break;
				if (mp[a[i]] > 0){
					if (a[i] == n){
						covered++;
						mp[a[i]]--;
						count++;
					}
					else if (a[i] < n){
						if (mp[n-a[i]] > 0){
							if (a[i] == n-a[i] && mp[a[i]] < 2) continue;
							mp[n-a[i]]--;
							mp[a[i]]--;
							covered++;
							count += 2;
						}
					}
				}
			}

			if (covered == need){
				ans = min(ans, count);
			}
		}

		if (ans == INF) cout << "impossivel" << endl;
		else cout << ans << endl;
	}

	return 0;
}