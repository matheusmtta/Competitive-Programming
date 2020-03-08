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

int n, k;
string core = "A23456789DQJK";
map <char, int> players[15];
map <char, int> sorting;
vector <int> ans;

char select(int p, bool last){
	if (!last && players[p]['C'] > 0)
		return 'C';
	else {
		int mn = INF;
		char s;
		for (auto i : players[p]){
			if (i.first != 'C'){
				if (i.second != 0){
					if (mn > i.second){
						s = i.first;
						mn = i.second;
					}
					if (mn == i.second){
						if (sorting[i.first] < sorting[s])
							s = i.first;
					}
				}
			}
		}
		return s;
	}
}

bool check(){
	bool rsp = false;
	for (int i = 0; i < n; i++){
		int sum = 0, mx = -1;
		for (auto j : players[i]){
			sum += j.second;
			mx = max(mx, j.second);
		}
		if (sum == 4 && mx == 4) {ans.push_back(i); rsp = true;}
	}
	return rsp;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	k--;

	for (int i = 0; i < core.size(); i++)
		sorting[core[i]] = i;

	sorting['C'] = -1;

	for (int i = 0; i < 15; i++){
		for (int j = 0; j < core.size(); j++){
			players[i][core[j]] = 0;
		}
		players[i]['C'] = 0;
	}

	for (int i = 0; i < n; i++){
		char c;
		for (int j = 0; j < 4; j++){
			cin >> c;
			players[i][c]++;
		}
	}

	bool last;
	char add = 'C';

	int x = 3;

	while (true){
		players[k][add]++;

		if (add == 'C') last = true;

		add = select(k, last);
		if (add == 'C') last = true;
		else last = false;

		players[k][add]--;

		if (check()) break;

		k = (k+1)%n;
	}

	sort(ans.begin(), ans.end());

	cout << ans[0]+1 << endl;

	return 0;
}