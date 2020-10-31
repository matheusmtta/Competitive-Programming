#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

//Find all occurrences o pattern t in a string s
//in O(|s|+|t|)

struct KMP {
	string s, t;
	int n, m;
	vector <int> pi;

	KMP(string s, string t) : s(s), t(t) {
		pi.resize(t.size()+1);
		prefix_function();
	}

	void prefix_function(){
		string p = t + "$";
		
		for (int i = 1, j = 0; i < p.size(); i++){
			while (j > 0 && t[i] != t[j])
				j = pi[j-1];
			if (t[i] == t[j])
				j++;
			pi[i] = j;
		}
	}

	vector <int> match(){
		vector <int> pos;
		for (int i = 0, j = 0; i < s.size(); i++){
			while (j > 0 && s[i] != t[j]) 
				j = pi[j-1];
			if (s[i] == t[j])
				j++;
			if (j == t.size())
				pos.push_back(i-j+1);
		}
		return pos;
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s, t; 
	cin >> s >> t;
	KMP kmp(s, t);
	vector <int> ans = kmp.match();

	return 0;
}