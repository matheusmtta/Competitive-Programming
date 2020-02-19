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

int R, C, N;

bool allow(int r, int c){
	if (r >= R || r < 0) return false;
	if (c >= C || c < 0) return false;
	return true;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q = 1;

	while (true){
		cin >> R >> C >> N;

		if (R == 0 && C == 0 && N == 0) return 0;

		bitset <10005> col, row;

		for (int i = 0; i < N; i++){
			int r, c; cin >> r >> c;
			row.set(r);
			col.set(c);
		}

		int move_r[5] = {0, 0, 1, 0, -1};
		int move_c[5] = {0, 1, 0, -1, 0};

		bool ans = true;

		int posr, posc;

		cin >> posr >> posc;

		for (int i = 0; i < 5; i++){
			int nr = posr + move_r[i];
			int nc = posc + move_c[i];

			if (allow(nr, nc) && !(row[nr]|col[nc])) {
				ans = false;
			}
		}

		cout << "Case " << q << ": ";

		if (!ans) cout << "Escaped again! More 2D grid problems!" << endl;
		else cout << "Party time! Let's find a restaurant!" << endl;

		q++;
	}

	return 0;
}