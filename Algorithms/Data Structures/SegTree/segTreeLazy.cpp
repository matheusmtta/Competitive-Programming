#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

//Recursive Segment tree with lazy propagation
//Build O(n)
//Query, sum of [l, r] elements in O(logn)
//Update, change the value of the eement at range [l, r] in O(logn) 

template <typename T> 
struct segTree {
	int n;
	vector <T> arr;
	vector <T> segtr, lazy;

	segTree(vector<T> &a, int n) : n(n), arr(a) {
		segtr.assign(4*n, 0);
		lazy.assign(4*n, 0);
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

	void prop(int v, int l, int r){
		if (!lazy[v]) return;
		
		int m = (l+r)/2, nxt = v << 1;

		segtr[nxt] += lazy[v]*(m - l + 1);
		segtr[nxt+1] += lazy[v]*(r - (m+1) + 1);
		lazy[nxt] += lazy[v], lazy[nxt+1] += lazy[v];
		lazy[v] = 0;
	}

	void update(int lx, int rx, T val) { T dummy = update(1, 0, n-1, lx, rx, val); }
	T query(int lx, int rx) { return query(1, 0, n-1, lx, rx); }

	T update(int v, int l, int r, int lx, int rx, T val){
		if (r < lx || l > rx) return segtr[v];
		if (l >= lx && r <= rx) {
			segtr[v] += val*(r-l+1);
			lazy[v] += val;
			return segtr[v];
		}
		
		int m = (l + r)/2, nxt = v << 1;

		prop(v, l, r);

		T s1 = update(nxt, l, m, lx, rx, val);
		T s2 = update(nxt+1, m+1, r, lx, rx, val);

		return segtr[v] = s1 + s2;
	}

	T query(int v, int l, int r, int lx, int rx){
		if (r < lx || l > rx) return 0;
		if (l >= lx && r <= rx)
			return segtr[v];
		
		int m = (l + r)/2, nxt = v << 1;

		prop(v, l, r);

		T s1 = query(nxt, l, m, lx, rx);
		T s2 = query(nxt+1, m+1, r, lx, rx);

		return s1 + s2;
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector <int64> a(n);

	for (int64 &x : a)
		cin >> x;

	segTree <int64> st(a, n);

	int l, r, val;
	st.update(l, r, val); //add val to the segment [l, r]
	st.query(l, r); //get sum at the segment [l, r]

	return 0;
}
	