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

	int n; 
	while (cin >> n){
		if (n == 0) return 0;
		vector <pair<int, int>> pos, neg;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			if (x > 0)
				pos.push_back({i+1, x});
			else
				neg.push_back({i+1, x});
		}

		int i = 0, j = 0; int64 ans = 0;

		while (i < pos.size() && j < neg.size()){
			int diff = min(abs(neg[j].second), pos[i].second);
			pos[i].second -= diff;
			neg[j].second += diff;
			ans += abs(pos[i].first-neg[j].first)*diff;
			if (pos[i].second == 0) i++;
			if (neg[j].second == 0) j++;
		}

		cout << ans << endl;
	}

	return 0;
}