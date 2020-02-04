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

	int n, a, b, k;
	vector <int> r;

	cin >> n >> a >> b >> k;

	int ans = 0, h;

	for (int i = 0; i < n; i++){
		cin >> h;
		int aux = a + b;

		if (h%(a+b) <= a){
			if (h%(a+b) == 0){
				h = (h - a)%(a+b);
				int x = h/a;
				if (h%a != 0) x++; 
				r.push_back(x);
			}
			else ans++;
		}

		else {
			h = (h - a)%(a+b);
			int y = h/a;
			if (h%a != 0) y++;
			r.push_back(y);
		}
	}

	sort(r.begin(), r.end());

	for (int i = 0; i < r.size(); i++){
		if (k - r[i] >= 0){
			ans++;
			k -= r[i];
		}
	}

	cout << ans << endl;

	return 0;
}