#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

//Given the number of inversions of an array [1, n]
//reconstruct the array

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
	T query(int lx, int rx, int k) { return query(1, 0, n-1, lx, rx, k); }

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

	T query(int v, int l, int r, int lx, int rx, int k){
		if (l == r)
			return l;

		int m = (l + r)/2, nxt = v << 1;

		int s2 = segtr[nxt+1];

		if (s2 > k)
			return query(nxt+1, m+1, r, lx, rx, k);
		else
			return query(nxt, l, m, lx, rx, k-s2);
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector <int> a(n);

	for (int &x : a)
		cin >> x;

	vector<int> ones(n, 1);
	vector<int> ans;

	segTree <int> st(ones, n);

	for (int i = n-1; i >= 0; i--){
		int x = st.query(0, n-1, a[i]);
		ans.push_back(x);
		st.update(x, 0);
	}
	reverse(ans.begin(), ans.end());
	for (auto x : ans)
		cout << x+1 << ' ';
	cout << endl;

	return 0;
}