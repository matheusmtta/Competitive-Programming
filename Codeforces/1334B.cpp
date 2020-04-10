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

bool compare(const int64 &a, const int64 &b){
	return a > b;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int64 n, x; cin >> n >> x;

		double sum = 0;

		vector <int64> p;

		for (int i = 0; i < n; i++){
			int64 y; cin >> y;
			p.push_back(y);
			sum += y;
		}

		sort(p.begin(), p.end(), compare);

		if (sum/n >= x) {cout << n << endl; continue;}
		else {
			int ans = 0;
			double aux = 0;

			for (int i = 0; i < n; i++){
				aux += p[i];
				if (aux/(ans+1) >= x)
					ans++;
				else aux -= p[i];
			}

			cout << ans << endl;
		}
	}

	return 0;
}