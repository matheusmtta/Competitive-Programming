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
	pi.resize(t.size(), 0);

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

	int ans = 0;
	for (int i = 0, j = 0; i < s.size(); i++){
		while (j > 0 && s[i] != t[j])
			j = pi[j-1];
		if (s[i] == t[j])
			j++;
		if (j > ans)
			ans = max(j, ans);
	}

	return ans;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		string p; p = s; 
		
		reverse(p.begin(), p.end());

		prefix_function(p);

		int ans = match(p, s);
		string rsp = s.substr(0, ans);

		reverse(rsp.begin(), rsp.end());

		cout << rsp << endl;
	}

	return 0;
}