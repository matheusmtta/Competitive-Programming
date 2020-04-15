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

vector <vector<pair<int, int>>> ans;
vector <pair<int, int>> basis;

void build(vector <pair<int, int>> &perm, int idx){
	ans.push_back(perm);

	for (int i = idx; i < basis.size(); i++){
		perm.push_back(basis[i]);
		build(perm, i+1);
		perm.pop_back();
	}

	return;
}

int get_max(vector <pair<int, int>> poss, vector <vector<char>> mtx){
	for (int i = 0; i < poss.size(); i++)
		mtx[poss[i].first][poss[i].second] = 'R';

	int t = 0;

	for (int i = 0; i < mtx.size(); i++){
		for (int j = 0; j < mtx[i].size(); j++){
			if (mtx[i][j] == 'R'){
				t++;
				for (int k = i+1; k < mtx.size(); k++){
					if (mtx[k][j] == 'X') break;
					if (mtx[k][j] == 'R') return -1;
				}
				for (int k = i-1; k >= 0; k--){
					if (mtx[k][j] == 'X') break;
					if (mtx[k][j] == 'R') return -1;
				}
				for (int k = j+1; k < mtx.size(); k++){
					if (mtx[i][k] == 'X') break;
					if (mtx[i][k] == 'R') return -1;
				}
				for (int k = j-1; k >= 0; k--){
					if (mtx[i][k] == 'X') break;
					if (mtx[i][k] == 'R') return -1;
				}
			}
		}
	}

	return t;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true){
		int n; cin >> n;	
		if (n == 0) exit(0);

		vector <vector<char>> mtx;

		for (int i = 0; i < n; i++){
			vector <char> tmp;
			for (int j = 0; j < n; j++){
				char x; cin >> x;
				tmp.push_back(x);
				if (x == '.')
					basis.push_back(MP(i, j));
			}
			mtx.push_back(tmp);
		}

		vector <pair<int, int>> perm;

		build(perm, 0);

		int rsp = -1;

		for (auto i : ans)
			rsp = max(get_max(i, mtx), rsp);

		cout << rsp << endl;

		ans.clear();
		basis.clear();
	}

	return 0;
}