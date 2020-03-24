#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

//Recursive Segment tree
//Build O(n)
//Query, sum of [l, r] elements in O(logn)
//Update, change the value of the eement at index 'i' in O(logn) 

const int MAXN = 1000;

int n;
vector <int> segt(4*MAXN);
vector <int> a;

void build(int v, int l, int r){
	if(l == r)
		segt[v] = a[l];
	else {
		int m = (l + r)/2;
		build(v*2, l, m);
		build(v*2+1, m+1, r);
		segt[v] = segt[v*2] + segt[v*2 + 1];
	}
}

int query(int v, int l, int r, int a, int b){
	if (a > b) 
		return 0;
	if (a == l && b == r)
		return segt[v];
	int m = (l + r)/2;
	return query(v*2, l, m, a, min(b, m))
		 + query(v*2+1, m+1, r, max(a, m+1), b); 
}

void update(int v, int l, int r, int p, int nw){
	if (l == r) segt[v] = nw;
	else {
		int m = (l + r)/2;
		if (p <= m)
			update(v*2, l, m, p, nw);
		else
			update(v*2+1, m+1, r, p, nw);
		segt[v] = segt[v*2] + segt[v*2+1];
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++){
		int x; cin >> x;
		a.push_back(x);
	}

	build(1, 0, n-1);


	cout << "Queries: " << endl;
	int q = 0; cin >> q;

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;

	for (int i = 0; i < q; i++){
		int l, r; cin >> l >> r;
		cout << query(1, 0, n-1, l, r) << endl;
	}

	cout << "Update: " << endl;

	cin >> q;

	for (int i = 0; i < q; i++){
		int idx, v; cin >> idx >> v;
		update(1, 0, n-1, idx, v);

	}

	return 0;
}