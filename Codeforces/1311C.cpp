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
		string str;
		int n, m; 
		cin >> n >> m;
		cin >> str;

		map <int, vector <int>> mp;

		for (int i = 0; i < n; i++){
			if (i == 0){
				mp[i].resize(26, 0);
				mp[i][str[i]-'a']++;
			}
			else{
				mp[i] = mp[i-1];
				mp[i][str[i]-'a']++;
			}
		}

		vector <int> ans(26, 0);
		
		for (int i = 0; i < m; i++){
			int x; cin >> x;
			for (int j = 0; j < 26; j++){
				ans[j] += mp[x-1][j];
			}
		}


		for (int i = 0; i < n; i++)
			ans[str[i]-'a']++;

		for (int i = 0; i < 26; i++){
			cout << ans[i];
			if (i != 25) cout << " ";
		}

		cout << endl;
	}

	return 0;
}