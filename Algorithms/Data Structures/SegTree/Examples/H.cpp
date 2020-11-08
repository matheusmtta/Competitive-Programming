#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

//Couting inversions with segtree

template <typename T> 
struct segTree {
	int n;
	vector <T> arr;
	vector <T> segtr;

	segTree(vector<T> &a, int n) : n(n), arr(a) {
		segtr.assign(4*n, 0);
		build(1, 0, n-1);
	}  

	T combine(T ax, T bx){
		return ax + bx;
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

	int n; cin >> n;
	vector <int> a(n);

	for (int &x : a)
		cin >> x;

	vector<int> zero(n+1, 0);

	segTree <int> st(zero, n+1);

	for (int i = 0; i < n; i++)
		cout << st.query(a[i], n) << ' ', st.update(a[i], 1);
	cout << endl;

	return 0;
}