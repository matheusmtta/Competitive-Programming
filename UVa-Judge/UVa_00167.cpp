#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int vec[8];
int mtx[8][8];
vector <int> ans;

bool allow(int r, int c){
	for (int i = 0; i < c; i++){
		if (vec[i] == r || abs(vec[i]-r) == abs(i-c))
			return false;
	}
	return true;
}

void solve(int c, int sum){
	if (c == 8) {ans.push_back(sum); return;}

	for (int r = 0; r < 8; r++){
		if (allow(r , c)){
			vec[c] = r;
			solve(c + 1, sum + mtx[r][c]);
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> mtx[i][j];

		solve(0, 0);

		int rsp = -1;

		for (auto i : ans)
		 	rsp = max(rsp, i);

		for (int i = 5-((int)log10(rsp)+1); i > 0; i--)
			cout << " ";

		cout << rsp << endl;

		ans.clear();
	}

	return 0;
}