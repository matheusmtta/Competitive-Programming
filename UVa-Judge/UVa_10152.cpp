#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		
		vector <int> final, curr;
		vector <string> aux;
		map <int, string> mp;
		map <string, int> rev;
		cin.ignore();
		
		for (int i = 0; i < n; i++){
			string str;
			getline(cin, str);
			aux.push_back(str);
		}

		for (int i = 0; i < n; i++){
			string str; getline(cin, str);
			final.push_back(i);
			rev[str] = i;
			mp[i] = str;
		}

		for (int i = 0; i < n; i++){
			curr.push_back(rev[aux[i]]);
		}

		vector <int> ans;
		int idx = curr.size()-1;

		for (int i = curr.size()-1; i >= 0; i--){
			if (idx != curr[i]) ans.push_back(curr[i]);
			else idx--;
		}

		sort(ans.begin(), ans.end());
		reverse(ans.begin(), ans.end());

		for (auto k : ans){
			cout << mp[k] << endl;
		}

		cout << endl;
	}

	return 0;
}