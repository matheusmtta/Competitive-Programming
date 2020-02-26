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

const int MAX = 200500;
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

int get_enemy(int x){
	return x+10000;
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

	int n; cin >> n;
	build();
	while (true){
		int x, y, c;
		cin >> c >> x >> y;

		if (c == 0 && x == 0 && y == 0) break;

		if (c == 1){
			if (find(x) == find(get_enemy(y))) {cout << -1 << endl; continue;}
			unio(x, y);
			unio(get_enemy(x), get_enemy(y));
		}

		if (c == 2){
			if (find(x) == find(y)) {cout << -1 << endl; continue;}
			unio(x, get_enemy(y));
			unio(y, get_enemy(x));
		}

		if (c == 3){
			find(x) == find(y) ? cout << 1 << endl : cout << 0 << endl;
		}

		if (c == 4){
			find(x) == find(get_enemy(y)) ? cout << 1 << endl : cout << 0 << endl;
		}
	}

	return 0;
}