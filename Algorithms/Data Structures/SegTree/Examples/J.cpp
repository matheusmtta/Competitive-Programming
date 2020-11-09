#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

//Find nested segments in array ex: xyyzxz
//yy is nested inside the segment x...x

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
		if (rx < l || lx > r) return 0;
		if (l >= lx && r <= rx) return segtr[v];

		int m = (l + r)/2, nxt = v << 1;

		int s1 = query(nxt, l, m, lx, rx);
		int s2 = query(nxt+1, m+1, r, lx, rx);

		return s1 + s2;
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector <int> arr(2*n);
	vector <int> zeros(2*n);

	for (int &x : arr)
		cin >> x;

	segTree <int> st(zeros, 2*n);

	vector <int> ans(n+1, 0);
	vector <int> visited(n+1, -1);

	for (int i = 0; i < 2*n; i++){
		if (visited[arr[i]] == -1)
			visited[arr[i]] = i;
		else {
			ans[arr[i]] = st.query(visited[arr[i]], i);
			st.update(visited[arr[i]], 1);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;

	return 0;
}
