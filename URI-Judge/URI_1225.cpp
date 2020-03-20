#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while (cin >> n){
		int64 me = 0;

		vector <int> a;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			a.push_back(x);
			me += x;
		}

		if (me%n != 0) {cout << -1 << endl; continue;}

		me/=n;

		sort(a.begin(), a.end());

		int i = 0, j = n-1;

		int64 ans = 0;

		while (i != j && i < j){
			if (a[i] < me && a[j] > me){
				int x = min(abs(a[i]-me), abs(a[j]-me));
				a[i] += x;
				a[j] -= x;
				ans += x;
			}
			if (a[i] == me) i++;
			if (a[j] == me) j--;
		}

		cout << ans+1 << endl;
	}	

	return 0;
}