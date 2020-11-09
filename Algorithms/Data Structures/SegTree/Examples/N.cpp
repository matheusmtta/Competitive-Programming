#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

//Assignment to Segment

template <typename T> 
struct segTree {
	int n;
	vector <T> arr;
	vector <T> segtr, lazy;

	segTree(vector<T> &a, int n) : n(n), arr(a) {
		segtr.assign(4*n, 0);
		lazy.assign(4*n, -1);
		build(1, 0, n-1);
	}

	T combine(T a, T b){
		return max(a, b);
	}  

	void build(int v, int l, int r){
		if (r == l)
			segtr[v] = arr[l];
		else {
			int m = (l + r)/2, nxt = v << 1;
			
			build(nxt, l, m);
			build(nxt + 1, m+1, r);
			
			segtr[v] = combine(segtr[nxt], segtr[nxt+1]);
		}
	}

	void prop(int v, int l, int r){
		if (lazy[v] == -1) return;
		
		int m = (l+r)/2, nxt = v << 1;

		segtr[nxt] = lazy[v];
		segtr[nxt+1] = lazy[v];
		lazy[nxt] = lazy[v], lazy[nxt+1] = lazy[v];
		lazy[v] = -1;
	}

	void update(int lx, int rx, T val) { T dummy = update(1, 0, n-1, lx, rx, val); }
	T query(int lx, int rx) { return query(1, 0, n-1, lx, rx); }

	T update(int v, int l, int r, int lx, int rx, T val){
		if (r < lx || l > rx) return segtr[v];
		if (l >= lx && r <= rx) {
			segtr[v] = val;
			lazy[v] = val;
			return segtr[v];
		}
		
		int m = (l + r)/2, nxt = v << 1;

		prop(v, l, r);

		T s1 = update(nxt, l, m, lx, rx, val);
		T s2 = update(nxt+1, m+1, r, lx, rx, val);

		return segtr[v] = combine(s1, s2);
	}

	T query(int v, int l, int r, int lx, int rx){
		if (r < lx || l > rx) return -INF;
		if (l >= lx && r <= rx)
			return segtr[v];
		
		int m = (l + r)/2, nxt = v << 1;

		prop(v, l, r);

		T s1 = query(nxt, l, m, lx, rx);
		T s2 = query(nxt+1, m+1, r, lx, rx);

		return combine(s1, s2);
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector <int> a(n, 0);

	segTree <int> st(a, n);

	while (m--){
		int cmd; cin >> cmd;
		if (cmd == 1){
			int l, r, val; cin >> l >> r >> val;
			st.update(l, r-1, val);
		}
		else{
			int i; cin >> i;
			cout << st.query(i, i) << endl;
		}
	}

	return 0;
}
	