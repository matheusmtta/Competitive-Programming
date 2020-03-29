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

const int MAXN = 100100;

int n, q;
vector <int> segt(4*MAXN);
vector <int> freq;

int build(int v, int l, int r) {
	if (l == r) 
		return segt[v] = freq[l];
	int m = (l+r)/2;
	return segt[v] = max(build(2*v, l, m), build(2*v + 1, m+1, r));
}

int query(int a, int b, int v, int l, int r) {
	if (b < l || r < a) 
		return 0;
	if (a <= l && r <= b) 
		return segt[v];
	int m = (l+r)/2;
	return max(query(a, b, 2*v, l, m), query(a, b, 2*v+1, m+1, r));
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n){
		if (n == 0) exit(0);
		cin >> q;

		map <int, int> count;
		vector <int> a;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			a.push_back(x);
			count[x]++;
		}

		for (int i = 0; i < n; i++){
			freq.push_back(count[a[i]]);
		}

		build(1, 0, n-1);
		
		for (int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			l--, r--;

			if (a[l] == a[r]){
				cout << r-l+1 << endl;
			}
			else {
				int ans1, ans2;
				ans1 = ans2 = 1;

				while (a[l] == a[l+1] && l <= r){
					l++;
					ans1++;
				}

				while (a[r] == a[r-1] && r >= l){
					r--;
					ans2++;
				}
				l++, r--;

				int ans = query(l, r, 1, 0, n-1);

				cout << max({ans, ans1, ans2}) << endl;
			}
		}

		freq.clear();
		segt.assign(4*MAXN, 0);
	}

	return 0;
}