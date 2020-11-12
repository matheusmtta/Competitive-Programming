#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back
#define endl "\n"

typedef long long int int64;
typedef unsigned long long int  uint64;

//range matrix multiplication 2x2 matrices Z_r

struct matrix {
	int64 mtx[2][2] = {0};
};

const int dim = 2;

void display(matrix A){
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++)
			printf("%lld ", A.mtx[i][j]);
		printf("\n");
	}
	printf("\n");
}

template <typename T> 
struct segTree {
	int n, r;
	vector <T> arr;
	vector <T> segtr;
	T I;

	segTree(vector<T> &a, int r, int n) : n(n), r(r), arr(a) {
		segtr.resize(4*n);
		build(1, 0, n-1);
		I.mtx[0][0] = I.mtx[1][1] = 1LL;
	}  

	matrix combine(matrix A, matrix B){
		matrix C;
		for (int i = 0; i < dim; i++)
			for (int j = 0; j < dim; j++)
				for (int k = 0; k < dim; k++)
					C.mtx[i][j] = (C.mtx[i][j] + A.mtx[i][k]*B.mtx[k][j])%r;
		return C;
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

	void update(int idx, T val) { update(1, 0, n-1, idx, val); }
	T query(int lx, int rx) { return query(1, 0, n-1, lx, rx); }

	void update(int v, int l, int r, int idx, T val){
		if (l == r)
			segtr[v] = val;
		else {
			int m = (l + r)/2, nxt = v << 1;
			
			if (idx <= m) update(nxt, l, m, idx, val);
			else update(nxt + 1, m+1, r, idx, val);
			
			segtr[v] = combine(segtr[nxt], segtr[nxt + 1]);
		}
	}

	T query(int v, int l, int r, int lx, int rx){
		if (r < lx || l > rx) return I;
		if (l >= lx && r <= rx)
			return segtr[v];
		
		int m = (l + r)/2, nxt = v << 1;

		T s1 = query(nxt, l, m, lx, rx);
		T s2 = query(nxt+1, m+1, r, lx, rx);

		return combine(s1, s2);
	}
};

int main(){	
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int r, n, m;
	cin >> r >> n >> m;
	vector <matrix> arr;

	for (int i = 0; i < n; i++){
		matrix x;
		for (int k = 0; k < 2; k++){
			for (int j = 0; j < 2; j++){
				scanf("%lld", &x.mtx[k][j]);
				x.mtx[k][j] %= r;
			}
		}
		arr.push_back(x);
	}

	segTree <matrix> segtr(arr, r, n);

	while (m--){
		int l, r; cin >> l >> r;
		l--; r--;
		matrix ans = segtr.query(l, r);
		display(ans);
	}

	return 0;
}