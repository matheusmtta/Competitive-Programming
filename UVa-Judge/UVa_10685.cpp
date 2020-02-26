 
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

const int MAX = 5005;

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

	while(true){
		int R, C; cin >> C >> R;
		if (R == 0 && C == 0) break;

		map <string, int> mp;

		for (int i = 1; i <= C; i++){
			string str; cin >> str;

			mp[str] = i;
			p[i] = i;
			sz[i] = 1;
		}

		for (int i = 0; i < R; i++){
			string a, b; cin >> a >> b;
			int x = mp[a];
			int y = mp[b];

			une(x, y);
		}

		int ans = -1;

		for (auto i : mp){
			if (sz[find(i.second)] > ans) ans = sz[find(i.second)];
		}

		cout << ans << endl;
	}

	return 0;
}