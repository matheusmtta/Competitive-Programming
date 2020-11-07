#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back
 
typedef long long int int64;
typedef unsigned long long int  uint64;
 
//find the first element at least k, from a given l to n-1
 
template <typename T> 
struct segTree {
	int n;
	T e;
	vector <T> arr;
	vector <T> segtr;
 
	T combine(T a, T b){
		return max(a, b);
	}
 
	segTree(vector<T> &a, int n) : n(n), arr(a) {
		e = -INF;
		segtr.assign(4*n, 0);
		build(1, 0, n-1);
	}  
 
	void build(int v, int l, int r){
		if (r == l){
			segtr[v] = arr[l];
		}
		else {
			int m = (l + r)/2, nxt = v << 1;
			
			build(nxt, l, m);
			build(nxt + 1, m+1, r);
			
			segtr[v] = combine(segtr[nxt], segtr[nxt+1]);
		}
	}
 
	void update(int idx, int val) { update(1, 0, n-1, idx, val); }
	T query(int lx, int rx, int k) { return query(1, 0, n-1, lx, rx, k); }
 
	void update(int v, int l, int r, int idx, T val){
		if (l == r){
			segtr[v] = val;
		}
		else {
			int m = (l + r)/2, nxt = v << 1;
			
			if (idx <= m) update(nxt, l, m, idx, val);
			else update(nxt + 1, m+1, r, idx, val);
			
			segtr[v] = combine(segtr[nxt], segtr[nxt + 1]);
		}
	}
 
	T query(int v, int l, int r, int lx, int rx, int k){
		if (r < lx || l > rx)
			return INF;
		if (l == r && segtr[v] >= k)
			return l;
		if (l == r)
			return INF;
 
		int m = (l + r)/2, nxt = v << 1;

		if (l >= lx && segtr[nxt] >= k)
			return query(nxt, l, m, lx, rx, k);
		else
			return min(query(nxt+1, m+1, r, lx, rx, k), query(nxt, l, m, lx, rx, k));
	}
};
 
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, m; cin >> n >> m;
	vector <int> a(n);
 
	for (int &x : a)
		cin >> x;
 
	segTree <int> st(a, n);
 
	while (m--){
		int cmd; cin >> cmd;
		if (cmd == 1){
			int idx, val; cin >> idx >> val;
			st.update(idx, val);
		}
		else{
			int k, l; cin >> k >> l;
			int ans = st.query(l, n-1, k);

			if (ans == INF)
				cout << -1 << endl;
			else
				cout << ans << endl;
		}
	}
 
	return 0;
}