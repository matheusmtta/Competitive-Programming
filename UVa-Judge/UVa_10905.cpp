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

bool compare(const string &a, const string &b){
	return b + a < a + b;
}

int main(){
	int t;
	while (true){
		cin >> t;
		if (t == 0) return 0;

		vector <string> strs;

		for (int i = 0; i < t; i++){
			string tmp; cin >> tmp;
			strs.push_back(tmp);
		}

		sort(strs.begin(), strs.end(), compare);

		string ans;

		for (int i = 0; i < strs.size(); i++)
			ans += strs[i];

		cout << ans << endl;
	}
	
	return 0;
}