#include <bits/stdc++.h>

using namespace std;

// COMPLEXIDADE O(mLogn)
// BUILD - O(n)
// FIND - O(log(n))
// UNE - O(log(n))

const int MAX = 0x3f3f3f3f;

vector <pair <int, pair <int, int> > > ar;
int n, m, p[MAX], sz[MAX], v[MAX];

//DSU, UNION-FIND

void build();
int find(int k);
void une(int a, int b);

void build(){
	for (int i = 0; i < n; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(int k){
	if (p[k] == k) return k;
	return find(p[k]);
}

void une(int a, int b){
	a = find(a); b = find(b);
	if (a == b) return;
	if (sz[a] > sz[b]) swap(a, b);

	sz[b] += sz[a];
	p[a] = b;
}

int kruskal(){
	build();
	sort(ar.begin(), ar.end());
	int sum = 0;
	for (int i = 0; i < (int) ar.size(); i++){
		int a = ar[i].second.first, b = ar[i].second.second;
		if (find(a) != find(b)){
			une(a, b);
			sum += ar[i].first;
		}
	}
	return sum;
}