#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 1000000;

int p[MAX], sz[MAX];

void buildDSU();
int findDSU(int k);
void unionDSU(int a, int b);

void buildDSU(){
	for (int i = 0; i < MAX; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int findDSU(int k){
	if (p[k] == k) return k;
	return findDSU(p[k]);
}

void unionDSU(int a, int b){
	a = findDSU(a); b = findDSU(b); 

	if (a == b) return;

	if (sz[a] > sz[b]) swap(a, b);

	sz[b] += sz[a];
	p[a] = b;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// COMPLEXIDADE
	// BUILD - O(n)
	// FIND - O(log(n))
	// UNE - O(log(n))

	return 0;
}