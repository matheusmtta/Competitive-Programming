 
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

const int MAX = 100010;

void build();
void une(int a, int b);
int find(int k);

int p[MAX], sz[MAX];

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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		
		map <string, int> f;

		for (int i = 0; i < n; i++){
			string a, b; cin >> a >> b;
			if (f.find(a) == f.end()){
				int idx = f.size()+1;
				p[idx] = idx;
				sz[idx] = 1;
				f[a] = idx;
			}
			if (f.find(b) == f.end()){
				int idx = f.size()+1;
				p[idx] = idx;
				sz[idx] = 1;
				f[b] = idx;
			}

			une(f[a], f[b]);

			int x = sz[find(f[a])];
			int y = sz[find(f[b])];

			cout << max(x, y) << endl;
		}
	}

	return 0;
}