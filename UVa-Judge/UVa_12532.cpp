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

int n, k;
vector <int> segt(4*MAXN);
vector <int> a;

void build(int v, int l, int r){
	if(l == r)
		segt[v] = a[l];
	else {
		int m = (l + r)/2;
		build(v*2, l, m);
		build(v*2+1, m+1, r);
		segt[v] = segt[v*2] * segt[v*2 + 1];
	}
}

int query(int v, int l, int r, int a, int b){
	if (a > b) 
		return 1;
	if (a == l && b == r)
		return segt[v];
	int m = (l + r)/2;
	return query(v*2, l, m, a, min(b, m))
		 * query(v*2+1, m+1, r, max(a, m+1), b); 
}

void update(int v, int l, int r, int p, int nw){
	if (l == r) segt[v] = nw;
	else {
		int m = (l + r)/2;
		if (p <= m)
			update(v*2, l, m, p, nw);
		else
			update(v*2+1, m+1, r, p, nw);
		segt[v] = segt[v*2] * segt[v*2+1];
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n >> k){
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			int aux;
			if (x == 0) aux = 0;
			if (x < 0) aux = -1;
			if (x > 0) aux = 1;
			a.push_back(aux);
		}

		string ans;

		build(1, 0, n-1);

		for (int i = 0; i < k; i++){
			char ch; cin >> ch;
			if (ch == 'P'){
				int l, r; cin >> l >> r;
				l--, r--;
				int x = query(1, 0, n-1, l, r);
				if (x == 0) ans += "0";
				if (x < 0) ans += "-";
				if (x > 0) ans += "+";
			}
			else {
				int idx, value, aux;
				cin >> idx >> value;
				idx--;
				if (value == 0) aux = 0;
				if (value < 0) aux = -1;
				if (value > 0) aux = 1;
				update(1, 0, n-1, idx, aux);
			}
		}

		cout << ans << endl;

		a.clear();
		segt.assign(4*MAXN, 0);
	}

	return 0;
}