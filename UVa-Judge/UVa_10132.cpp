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

	string cases;
    getline(cin, cases);
    size_t t;
    istringstream ss(cases);
    ss >> t;
    
    getline(cin, cases);

	while (t--){

		string str;
		map <string, int> mp;
		vector <string> strs;
		string ans;
		int mx = -1;
		int s1, s2;
		s1 = INF;
		s2 = -1;

		while (getline(cin, str) && !str.empty()){
			strs.push_back(str);
			int sz = str.length();
			s1 = min(sz, s1);
			s2 = max(sz, s2);

			for (int i = 0; i < strs.size(); i++){
				for (int j = i+1; j < strs.size(); j++){
					mp[strs[i]+strs[j]]++;
					mp[strs[j]+strs[i]]++;
				}
			}
		}
		
		for (auto i : mp){
			//cout << i.first << " " << i.second << endl;
			if (i.second > mx && i.first.length() == s1+s2){
				mx = i.second;
				ans = i.first;
			}
		}

		//cout << "------------" << endl;

		cout << ans << endl;

		if (t) cout << endl;
	}

	return 0;
}