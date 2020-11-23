#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define end "\n"
#define first f
#define second s
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> pi;

void prefix_function(string  t){
	t += "$"; 
	for (int i = 1, j = 0; i < t.size(); i++){
		while (j > 0 && t[i] != t[j])
			j = pi[j-1];
		if (t[i] == t[j])
			j++;
		pi[i] = j;
	}
}

int match(string s, string t){
	int count = 0;
	for (int i = 0, j = 0; i < s.size(); i++){
		while (j > 0 && s[i] != t[j])
			j = pi[j-1];
		if (s[i] == t[j])
			j++;
		if (j == t.size())
			count++;
	}
	return count;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		string str; cin >> str;
		pi.resize((int)str.size()+1, 0);
		prefix_function(str);
		string s = str + str;
		int count = match(s, str);
		cout << (int)str.size()/(count-1) << endl;
		if (t) cout << endl;
	}

	return 0;
}
