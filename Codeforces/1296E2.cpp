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

	int n; cin >> n;
	string str; cin >> str;

	vector <pair <int, char>> basis;

	basis.push_back(MP(1, 'a'));

	int aux = 2;

	vector <int> ans;
	int mx = 1;

	for (int i = 0; i < str.length(); i++){
		bool flag = false;
		for (int j = 0; j < basis.size(); j++){
			if (str[i] >= basis[j].second) {
				ans.push_back(basis[j].first);
				basis[j].second = str[i];
				flag = true;
				break;
			}
		}
		if (!flag) {basis.push_back(MP(aux, str[i])); ans.push_back(aux); aux++;}
	}


	for (int i = 0; i < ans.size(); i++)
		mx = max(ans[i], mx);

	cout << mx << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}