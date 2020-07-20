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

	int n;
	while (cin >> n){
		if (n == 0) return 0;
		vector <pair<int64, int>> a, b;
		for (int i = 0; i < n; i++){
			int64 x; cin >> x;
			if (x > 0) a.push_back({x, i+1});
			if (x < 0) b.push_back({x, i+1});

		}

		int i = 0, j = 0;
		int64 ans = 0;
		
		while (i < a.size() && j < b.size()){
			int diff = min(abs(b[j].first), a[i].first);
			a[i].first -= diff;
			b[j].first += diff;
			ans += abs(a[i].second-b[j].second)*diff;
			if (a[i].first == 0) i++;
			if (b[j].first == 0) j++;
		}
		
		cout << ans << endl;
	}	

	return 0;
}