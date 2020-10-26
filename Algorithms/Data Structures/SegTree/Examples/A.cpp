#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

//Recursive Segment tree
//Build O(n)
//Query, sum of [l, r] elements in O(logn)
//Update, change the value of the eement at index 'i' in O(logn) 

template <typename T> 
struct segTree {
	int n;
	vector <T> arr;
	vector <T> segtr;

	segTree(vector<T> &a, int n) : n(n), arr(a) {
		segtr.assign(4*n, 0);
		build(1, 0, n-1);
	}  

	void build(int v, int l, int r){
		if (r == l)
			segtr[v] = arr[l];
		else {
			int m = (l + r)/2, nxt = v << 1;
			
			build(nxt, l, m);
			build(nxt + 1, m+1, r);
			
			segtr[v] = segtr[nxt] + segtr[nxt+1];
		}
	}

	void update(int idx, T val) { update(1, 0, n-1, idx, val); }
	T query(int lx, int rx) { return query(1, 0, n-1, lx, rx); }

	void update(int v, int l, int r, int idx, T val){
		if (l == r)
			segtr[v] = val;
		else {
			int m = (l + r)/2, nxt = v << 1;
			
			if (idx <= m) update(nxt, l, m, idx, val);
			else update(nxt + 1, m+1, r, idx, val);
			
			segtr[v] = segtr[nxt] + segtr[nxt + 1];
		}
	}

	T query(int v, int l, int r, int lx, int rx){
		if (r < lx || l > rx) return 0;
		if (l >= lx && r <= rx)
			return segtr[v];
		
		int m = (l + r)/2, nxt = v << 1;

		T s1 = query(nxt, l, m, lx, rx);
		T s2 = query(nxt+1, m+1, r, lx, rx);

		return s1 + s2;
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	vector <int64> a(n);

	for (int64 &x : a)
		cin >> x;

	segTree <int64> st(a, n);

	while (m--){
		int c, l, r; cin >> c >> l >> r;
		if (c == 1)
			st.update(l, r);
		if (c == 2)
			cout << st.query(l, r-1) << endl;
	}

	return 0;
}