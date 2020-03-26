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

int n, q, m;
vector <bitset<60>> segt(4*MAXN);
bitset <60> zer;
bitset <60> one;
vector <int> a;

void build(int v, int l, int r){
	if(l == r)
		segt[v][a[l]] = 1;
	else {
		int m = (l + r)/2;
		build(v*2, l, m);
		build(v*2+1, m+1, r);
		segt[v] = segt[v*2] | segt[v*2 + 1];
	}
}

bitset <60> query(int v, int l, int r, int a, int b){
	if (a > b) 
		return zer;
	if (a == l && b == r)
		return segt[v];
	int m = (l + r)/2;
	return query(v*2, l, m, a, min(b, m)) | query(v*2+1, m+1, r, max(a, m+1), b); 
}

void update(int v, int l, int r, int p, int nw){
	if (l == r){
		segt[v] &= zer;
		segt[v][nw] = 1;
	}
	else {
		int m = (l + r)/2;
		if (p <= m)
			update(v*2, l, m, p, nw);
		else
			update(v*2+1, m+1, r, p, nw);
		segt[v] = segt[v*2] | segt[v*2+1];
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n >> q >> m){
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			a.push_back(x);
		}

		build(1, 0, n-1);

		for (int i = 0; i < q; i++){
			int cmd, l, r; cin >> cmd >> l >> r;
			if (cmd == 1){
				l--; r--;
				bitset <60> ans = query(1, 0, n-1, l, r);
				cout << ans.count() << endl;
			}
			else {
				l--;
				update(1, 0, n-1, l, r);
			}
		}

		a.clear();

		for (int i = 0; i < 4*MAXN; i++)
			segt[i].reset();
	}

	return 0;
}