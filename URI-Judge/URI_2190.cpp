 
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

const int MAX = 200;

vector <pair <int, pair <int, int> > > ar;
int n, m, p[MAX], sz[MAX], v[MAX];
vector <pair <int, int>> ans;

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

void kruskal(){
	build();
	sort(ar.begin(), ar.end());
	for (int i = 0; i < (int) ar.size(); i++){
		int a = ar[i].second.first, b = ar[i].second.second;
		if (find(a) != find(b)){
			une(a, b);
			ans.push_back(MP(a, b));
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q = 1;

	while (true){
		cin >> n;

		if (n == 0) return 0;

		cin >> m;

		for (int i = 0; i < m; i++){
			int x, y, w; cin >> x >> y >> w;
			if (y < x) swap(x, y);
			ar.push_back(MP(w, MP(x, y)));
		}

		kruskal();

		cout << "Teste " << q << endl;

		for (int i = 0; i < ans.size(); i++){
			cout << ans[i].first << " " << ans[i].second << endl;
		}
		cout << endl;

		ans.clear();
		ar.clear();

		q++;
	}

	return 0;
}