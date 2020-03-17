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

const int MAX = 70;

vector <pair <int, pair <int, int> > > ar;
int n, m, p[MAX], sz[MAX], v[MAX];

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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		ar.push_back(MP(w, MP(x, y)));
	}

	cout << kruskal() << endl;

	return 0;
}