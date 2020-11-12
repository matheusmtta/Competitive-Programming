#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

//Computes alternating sum on a segment

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

	int n; cin >> n;
	vector <int64> a(n, 0);
	vector <int64> b(n, 0);

	for (int i = 0; i < n; i++){
		i%2 == 0 ? cin >> a[i] : cin >> b[i];
		i%2 == 0 ? b[i] = 0 : a[i] = 0;
	}

	segTree <int64> even(a, n), odd(b, n);

	int m; cin >> m;
	for (int i = 0; i < m; i++){
		int cmd; cin >> cmd;
		int a, b; cin >> a >> b;
		if (cmd == 0){
			a--;
			if (a%2 == 0) even.update(a, b);
			else odd.update(a, b);
		}
		else {
			a--; b--;
			if (a%2 == 0) cout << -(-even.query(a, b) + odd.query(a, b)) << endl;
			else cout << -(even.query(a, b) - odd.query(a, b)) << endl;
		}
	}

	return 0;
}
