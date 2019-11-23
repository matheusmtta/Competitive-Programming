#include <bits/stdc++.h>

using namespace std;

// COMPLEXIDADE
// BUILD - O(n)
// FIND - O(log(n))
// UNE - O(log(n))

const int MAX = 0x3f3f3f3f;

int p[MAX], sz[MAX];

//DSU, UNION-FIND

void build();
int find(int k);
void une(int a, int b);

void build(){
	for (int i = 0; i < MAX; i++){
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