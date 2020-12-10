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
	pi.assign(t.size(), 0);

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

	int j = 0;
	for (int i = 0; i < s.size(); i++){
		while (j > 0 && s[i] != t[j])
			j = pi[j-1];
		if (s[i] == t[j])
			j++;
	}
	return j;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> k >> n;
		string s; cin >> s;
		for (int i = 1; i < n; i++){
			string t; cin >> t;
			prefix_function(t);

			int init = match(s, t);
			
			for (int j = init; j < t.size(); j++)
				s += t[j];
		}
		cout << s.size() << endl;
	}

	return 0;
}