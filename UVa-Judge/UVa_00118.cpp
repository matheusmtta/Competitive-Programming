#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;

	map <char, int> mp;
	map <int, char> mp2;

	mp['N'] = 0; mp2[0] = 'N';
	mp['E'] = 1; mp2[1] = 'E';
	mp['S'] = 2; mp2[2] = 'S';
	mp['W'] = 3; mp2[3] = 'W';

	int my[4] = {1, 0, -1, 0};
	int mx[4] = {0, 1, 0, -1};

	int x, y; char dir;
	set <pair<int, int>> st;

	while (cin >> x >> y >> dir){
		string str; cin >> str;
		
		int idx = mp[dir];
		bool flag = false;
		
		for (int i = 0; i < str.size(); i++){
			if (str[i] == 'F'){
				int nx = x + mx[idx];
				int ny = y + my[idx];
				if (nx < 0 || ny < 0 || nx > n || ny > m){
					if (st.find({x, y}) == st.end()){
						st.insert({x, y});
						flag = true;
						break;
					}
					else continue;
				}
				else {
					x = nx;
					y = ny;
				}
			}
			else {
				if (str[i] == 'R')
					idx = (idx+1)%4;
				else
					idx = (idx-1+4)%4;
			}
		}

		cout << x << " " << y << " " << mp2[idx];
		flag ? cout << " LOST" : cout << "";
		cout << endl;
	}

	return 0;
}