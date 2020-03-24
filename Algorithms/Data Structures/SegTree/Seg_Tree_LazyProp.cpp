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

//Recursive Segment tree with Lazy Propagation
//Build O(n)
//Query, sum of [l, r] elements in O(logn)
//Update, increase the elements of [l, r] by 'x' in O(logn) 

const int MAXN = 100100;

int n;
vector <int64> segt(4*MAXN);
vector <int64> lazy(4*MAXN);
vector <int> a;

int64 build(int v, int l, int r) {
	lazy[v] = 0;
	if (l == r) 
		return segt[v] = a[l];
	int m = (l+r)/2;
	return segt[v] = build(2*v, l, m) + build(2*v + 1, m+1, r);
}


void push(int v, int l, int r) {
	if (!lazy[v]) 
		return;

	int m = (l+r)/2;
	segt[2*v] += lazy[v]*(m - l + 1);
	segt[2*v+1] += lazy[v]*(r - (m + 1) + 1);
	lazy[2*v] += lazy[v], lazy[2*v + 1] += lazy[v];
	lazy[v] = 0;
}

int64 query(int a, int b, int v, int l, int r) {
	if (b < l || r < a) 
		return 0;
	if (a <= l && r <= b) 
		return segt[v];
	push(v, l, r);
	int m = (l+r)/2;
	return query(a, b, 2*v, l, m) + query(a, b, 2*v+1, m+1, r);
}

int64 update(int a, int b, int nw, int v, int l, int r) {
	if (b < l || r < a) 
		return segt[v];
	if (a <= l && r <= b) {
		segt[v] += (int64)nw*(r - l + 1);
		lazy[v] += nw;
		return segt[v];
	}
	push(v, l, r);
	int m = (l + r)/2;
	return segt[v] = update(a, b, nw, 2*v, l, m) +
					 update(a, b, nw, 2*v+1, m+1, r);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	build(1, 1, n);
	update(l, r, nw, 1, 0, n-1);
	query(l, r, 1, 0, n-1);

	return 0;
}