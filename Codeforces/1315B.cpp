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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int a, b, p; cin >> a >> b >> p;

		string str; cin >> str;

		map <char, int> mp;

		mp['A'] = a;
		mp['B'] = b;

		if ((p < a && p < b) || str.length() == 1) {cout << str.length() << endl; continue;}
		if (str.length() == 2){
			if (mp[str[0]] <= p) cout << 1 << endl;
			else cout << 2 << endl;
			continue;
		}

		int sz = (int)str.length();

		char curr = str[0];

		vector <pair<char, int>> path;

		for (int i = 1; i < sz; i++){
			if (str[i] != curr || i == sz-1){
				path.push_back(MP(curr, i+1));
				curr = str[i];
			}
		}

		reverse(path.begin(), path.end());

		char trans;
		int pos;

		if (p - mp[path[0].first] < 0) {cout << str.length() << endl; continue;}

		for (int i = 0; i < path.size(); i++){
			p -= mp[path[i].first];
			if (p < 0) break;
			trans = path[i].first;
			pos = path[i].second;
		}

		pos -= 2;
		curr = str[pos];

		while (pos >= 0 && str[pos] == curr){
			pos--;
		}
		
		cout << pos+2 << endl;
	}

	return 0;
}