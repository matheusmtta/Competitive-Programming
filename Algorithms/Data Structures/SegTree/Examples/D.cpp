#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

//computes maximum range sum in logn with updates

struct node{
	int64 sum, pref, suf, seg;
};

template <typename T> 
struct segTree {
	int n;
	node e;
	vector <int64> arr;
	vector <T> segtr;

	node combine(node a, node b){
		node ans;
		ans.sum  = a.sum + b.sum;
		ans.pref = max(a.pref, a.sum+b.pref);
		ans.suf  = max(a.suf + b.sum, b.suf);
		ans.seg  = max({ans.sum, a.suf + b.pref, a.seg, b.seg});
		return ans;
	}

	segTree(vector<int64> &a, int n) : n(n), arr(a) {
		e.sum = e.pref = e.suf = e.seg = 0;
		segtr.resize(4*n);
		build(1, 0, n-1);
	}  

	void build(int v, int l, int r){
		if (r == l){
			segtr[v].pref = segtr[v].suf = segtr[v].seg = arr[l] > 0 ? arr[l] : 0;
			segtr[v].sum  = arr[l];
		}
		else {
			int m = (l + r)/2, nxt = v << 1;
			
			build(nxt, l, m);
			build(nxt + 1, m+1, r);
			
			segtr[v] = combine(segtr[nxt], segtr[nxt+1]);
		}
	}

	void update(int idx, int64 val) { update(1, 0, n-1, idx, val); }
	T query(int lx, int rx) { return query(1, 0, n-1, lx, rx); }

	void update(int v, int l, int r, int idx, int64 val){
		if (l == r){
			segtr[v].pref = segtr[v].suf = segtr[v].seg = val > 0 ? val : 0;
			segtr[v].sum = val;
		}
		else {
			int m = (l + r)/2, nxt = v << 1;
			
			if (idx <= m) update(nxt, l, m, idx, val);
			else update(nxt + 1, m+1, r, idx, val);
			
			segtr[v] = combine(segtr[nxt], segtr[nxt + 1]);
		}
	}

	T query(int v, int l, int r, int lx, int rx){
		if (r < lx || l > rx) return e;
		if (l >= lx && r <= rx)
			return segtr[v];
		
		int m = (l + r)/2, nxt = v << 1;

		T s1 = query(nxt, l, m, lx, rx);
		T s2 = query(nxt+1, m+1, r, lx, rx);

		return combine(s1, s2);
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector <int64> a(n);

	for (int64 &x : a)
		cin >> x;

	segTree <node> st(a, n);

	cout << st.query(0, n-1).seg << endl;
	while (m--){
		int idx, val; cin >> idx >> val;
		st.update(idx, val);
		cout << st.query(0, n-1).seg << endl;
	}

	return 0;
}