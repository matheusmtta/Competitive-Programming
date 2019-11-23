#include <bits/stdc++.h>

using namespace std;

const int MAX = 50001;

int n, m;

vector <pair <int, pair <int, int> > > arr;
int sz[MAX], p[MAX], v[MAX];

int find(int k);
void une(int a, int b);
void build();

void build(){
	for (int i = 0; i < MAX; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(int k){
	if (k == p[k]) return k;
	return find(p[k]);
}

void une(int a, int b){
	a = find(a), b = find(b);
	if (a == b) return;
	if (sz[a] > sz[b]) swap(a, b);

	sz[b] += sz[a];
	p[a] = b;
}

long long int kruskal(){
	build();
	sort(arr.begin(), arr.end());
	long long int sum = 0;
	for (int i = 0; i < (int) arr.size(); i++){
		int a = arr[i].second.first, b = arr[i].second.second;
		if (find(a) != find(b)){
			une(a, b);
			sum += arr[i].first;
		}
	}
	return sum;
}

int main(){
	while(1){
		cin >> n >> m;
		if (n == 0 && m == 0) return 0;
		for (int i = 0; i < m; i++){
			int x, y, w; cin >> x >> y >> w;
			arr.push_back(make_pair(w, make_pair(x, y)));
		}

		cout << kruskal() << endl;

		for (int i = 0; i < n; i++)
			sz[i] = p[i] = v[i] = 0;
	}
}