#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back
#define MAX 1000

typedef long long int int64;
typedef unsigned long long int  uint64;

map <string, int> memo;

int dp(string str){
	if (str.size() == 0)
		return 1;

	if (memo.count(str))
		return memo[str];

	int &curr = memo[str];

	curr = 0;

	for (int i = 0; i < str.size(); i++){
		int j = i+1;
		while (j < str.size() && str[j] == str[j-1]) {
			j++;
		}
		if (j - i > 1){
			string aux;
			for (int k = 0; k < i; k++)
				aux += str[k];
			for (int k = j; k < str.size(); k++)
				aux += str[k];
			curr = max(curr, dp(aux));
		}
	}

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		string str; cin >> str;

		cout << dp(str) << endl;
	}

	return 0;
}