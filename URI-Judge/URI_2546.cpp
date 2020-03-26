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

const int MAXN = 100100;

int n, c;
vector <pair<int, int64>> segt(4*MAXN);
vector <int64> lazy(4*MAXN);
vector <pair<int, int64>> a;

pair <int, int64> combine(pair<int, int64> a, pair <int, int64> b){
	if (a.second > b.second) return a;
	if (a.second == b.second) {
		if (a.first < b.first)
			return a;
		return b;
	}
	return b;
}

pair<int, int64> build(int v, int l, int r) {
	if (l == r) 
		return segt[v] = a[l];
	int m = (l+r)/2;
	return segt[v] = combine(build(2*v, l, m), build(2*v + 1, m+1, r));
}


void push(int v, int l, int r) {
	segt[2*v].second += lazy[v];
	lazy[2*v] += lazy[v];
	segt[2*v+1].second += lazy[v];
	lazy[2*v+1] += lazy[v];
	lazy[v] = 0;
}

pair <int, int64> query(int a, int b, int v, int l, int r) {
	if (b < l || r < a) 
		return MP(-INF, -LINF);
	if (a <= l && r <= b) 
		return segt[v];
	push(v, l, r);
	int m = (l+r)/2;
	return combine(query(a, b, 2*v, l, m), query(a, b, 2*v+1, m+1, r));
}

pair<int, int64> update(int a, int b, int nw, int v, int l, int r) {
	if (b < l || r < a) 
		return segt[v];
	if (a <= l && r <= b) {
		segt[v].second += (int64)nw;
		lazy[v] += nw;
		return segt[v];
	}
	push(v, l, r);
	int m = (l + r)/2;
	return segt[v] = combine(update(a, b, nw, 2*v, l, m),
					 update(a, b, nw, 2*v+1, m+1, r));
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> c){
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			a.push_back(MP(i+1, x));
		}

		build(1, 0, n-1);

		for (int i = 0; i < c; i++){
			char cmd; cin >> cmd;
			if (cmd == 'C'){
				int x, y; cin >> x >> y;
				x--;
				y--;
				pair <int, int64> ans = query(x, y, 1, 0, n-1);

				cout << ans.first << endl;

			}
			else {
				int x, y, z; cin >> x >> y >> z;
				x--;
				y--;
				update(x, y, z, 1, 0, n-1);
			}
		}

		a.clear();
		for (int i = 0; i < 4*MAXN; i++){
			segt[i].first = segt[i].second = lazy[i] = 0;
		}
	}

	return 0;
}