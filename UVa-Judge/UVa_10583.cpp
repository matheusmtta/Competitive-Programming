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

const int MAX = 50005;
int n;

void build();
int find(int k);
void unio(int a, int b);

int f[MAX], sz[MAX];

void build(){
	for (int i = 0; i <= MAX; i++){
		f[i] = i;
		sz[i] = 1;
	}
}

void unio(int a, int b){
	a = find(a), b = find(b);

	if (a == b) return;

	if (sz[a] > sz[b]) swap(a, b);

	sz[b] += sz[a];
	f[a] = b;
}

int find(int k){
	if (k == f[k]) return k;
	return find(f[k]);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q = 1;

	while (true){
		int n, m; cin >> n >> m;
		if (n == 0 && m == 0) break;

		build();

		for (int i = 0; i < m; i++){
			int x, y; cin >> x >> y;
			unio(x, y);
		}

		set <int> ans;

		for (int i = 1; i <= n; i++){
			ans.insert(find(i));
		}

		cout << "Case " << q << ":";
		cout << " " << ans.size() << endl;
		q++;
	}

	return 0;
}