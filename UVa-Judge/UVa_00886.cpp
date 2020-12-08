#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> pi;

void prefix_function(string t){
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
	t += "$";
	int count = 0;

	for (int i = 0, j = 0; i < s.size(); i++){
		while (j > 0 && s[i] != t[j])
			j = pi[j-1];
		if (s[i] == t[j])
			j++;
		if (j+1 == t.size())
			count++;
	}
	return count;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	while (true){
		cin >> str;
		if (str == ".")
			break;
		pi.resize(str.size()+1, 0);
		string s = str + str;
		prefix_function(str);
		cout << match(s, str)-1 << endl;
	}

	return 0;
}