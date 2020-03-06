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

bool compare(const pair <int, pair <int, int>> &a,
			 const pair <int, pair <int, int>> &b){
	return a.first > b.first;
}

const int MAX = 1000005;

vector <pair <int, pair <int, int> > > ar;
int n, m, p[MAX], sz[MAX], v[MAX];

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

int kruskal(){
	build();
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

	int m; cin >> m;

	for (int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		ar.push_back(MP(w, MP(x,y)));
	}
	
	sort(ar.begin(), ar.end());

	int ans1 = kruskal();

	sort(ar.begin(), ar.end(), compare);

	int ans2 = kruskal();

	cout << ans2 << endl << ans1 << endl;

	return 0;
}