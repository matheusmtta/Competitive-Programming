#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define PB push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

//Sparse table for RMQ, preprocessing in O(nlogn)
//computes RMQ from [l, r], as min(st[l][c], st[r-2^c+1][j])
//where c = log2(r - l + 1) in O(1)

template <typename T> 
struct sparseTable {
	int n, k;
	vector <T> arr;
	vector <T> log;
	vector <vector<T>> spt;

	sparseTable(vector<T> &a, int n) : n(n), arr(a), k((int)(log2(n)+1)) {
		spt.resize(n+1, vector<T>(k+1, 0));
		log.resize(n+1, 0);

		for (auto x : spt) 
			x.resize(k+1);

		for (int i = 2; i <= n; i++) 
			log[i] = log[i/2] + 1;
		
		build();
	}  

	void build(){
		for (int i = 0; i < n; i++)
			spt[i][0] = arr[i];

		for (int j = 1; j <= k; j++)
			for (int i = 0; i + (1 << j) <= n; i++)
				spt[i][j] = min(spt[i][j-1], spt[i + (1 << (j - 1))][j-1]);
	}

	T query(int lx, int rx) {  
		int c = log[rx - lx + 1];
		return min(spt[lx][c], spt[rx - (1 << c) + 1][c]);
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n;
	vector <int64> a(n);

	for (int64 &x : a)
		cin >> x;

	cin >> m;

	sparseTable <int64> st(a, n);

	int l, r; cin >> l >> r;

	cout << st.query(l, r) << endl;

	return 0;
}
