#include <bits/stdc++.h>

using namespace std;

#define MOD 0x3f3f3f3f
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAXN = 110;
const int MAXW = 51;

int memo[MAXN][MAXW];
int w[MAXN], g[MAXN];
vector <int> r;
int p;

int DP(int idx, int capacity){
  if (capacity < 0) return -INF;
  if (idx==p) return 0;
  int & q = memo[idx][capacity];
  if (q != -1) return q;
  return q = max(DP(idx+1, capacity), g[idx] + DP(idx+1, capacity-w[idx]));

}

void recover(int idx, int capacity){
	if (idx == p) return;

	int pick = g[idx] + DP(idx+1, capacity-w[idx]);
	int left = DP(idx+1, capacity);

	if (pick >= left){
		r.push_back(idx);
		recover(idx+1, capacity-w[idx]);
	}
	else {
		recover(idx+1, capacity);
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		cin >> p;

		for (int i = 0; i < MAXN; i++){
			w[i] = g[i] = 0;
			for (int j = 0; j < MAXW; j++)
				memo[i][j] = -1;
		}


		for (int i = 0; i < p; i++){
			cin >> g[i] >> w[i];
		}

		int ans = DP(0, 50);
		recover(0, 50);

		int wgt = 0;

		for (auto i : r)
			wgt += w[i];

		cout << ans << " brinquedos" << endl;
		cout << "Peso: " << wgt << " kg" << endl;
		cout << "sobra(m) " << p-r.size() << " pacote(s)" << endl;

		cout << endl;
		r.clear();
	}

	return 0;
}