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

map <char, pair <int, int>> mp;
int memo[440][440];
string a, b;

char mtx[25][25]; //letter grid

int LCS(int i, int j){
	if (i == a.size() || j == b.size()) return 0;

	int &qry = memo[i][j];

	if (qry != -1) return qry;

	qry = 0;

	if (a[i] == b[j]) qry = max(qry, 1 + LCS(i+1, j+1));

	return qry = max({qry, LCS(i+1, j), LCS(i, j+1)});

	return 0;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	mp['E'].first = 0;
	mp['E'].second = 1;

	mp['N'].first = -1;
	mp['N'].second = 0;

	mp['S'].first = 1;
	mp['S'].second = 0;

	mp['W'].first = 0;
	mp['W'].second = -1;

	int t; cin >> t;
	int q = 1;

	while (t--){
		int h, w; cin >> h >> w;

		memset(memo, -1, sizeof(memo));

		for (int i = 1; i <= h; i++){
			for (int j = 1; j <= w; j++){
				cin >> mtx[i][j];
			}
		}

		int x, y, s;
		
		cin >> s >> x >> y;

		char cmd;

		a += mtx[x][y];

		for (int i = 0; i < s; i++){
			cin >> cmd;
			x += mp[cmd].first;
			y += mp[cmd].second;
			a += mtx[x][y];
		}

		cin >> s >> x >> y;

		b += mtx[x][y];

		for (int i = 0; i < s; i++){
			cin >> cmd;
			x += mp[cmd].first;
			y += mp[cmd].second;
			b += mtx[x][y];
		}
		
		int ans = LCS(0, 0);

		cout << "Case " << q << ": " << a.size()-ans << " " << b.size()-ans << endl;

		a.clear(), b.clear();
		q++;
	}

	return 0;
}