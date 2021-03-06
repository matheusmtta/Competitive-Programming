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
	string t;
	vector <int> pi;
	vector <vector<int>> aut;
 
	KMP(string t) : t(t+"$") {
		pi.resize(t.size()+1, 0);
		aut.resize(t.size()+1, vector<int>(27, 0));
		//buildAut();
		prefix_function();
	}
 	

	void prefix_function(){
		for (int i = 1, j = 0; i < t.size(); i++){
			while (j > 0 && t[i] != t[j])
				j = pi[j-1];
			if (t[i] == t[j])
				j++;
			pi[i] = j;
		}
	}
 
	void buildAut(){
		prefix_function();
 
		for (int i = 0; i < t.size(); i++){
			for (int c = 0; c < 26; c++){
				if (i > 0 && 'a'+c != t[i])
					aut[i][c] = aut[pi[i - 1]][c];
				else
					aut[i][c] = i + ('a' + c == t[i]);
			}
		}
	}

	vector <int> matchAut(string s){
		vector <int> pos;
		int idx = 0;
		for (int i = 0; i < s.size(); i++){
			idx = aut[idx][s[i] - 'a'];
			if (idx+1 == t.size())
				pos.push_back(i-idx+1);
		}

		return pos;
	}
 	
	vector <int> match(string s){
		vector <int> pos;
		for (int i = 0, j = 0; i < s.size(); i++){
			while (j > 0 && s[i] != t[j]) 
				j = pi[j-1];
			if (s[i] == t[j])
				j++;
			if (j+1 == t.size())
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
	KMP kmp(t);

	vector <int> ans = kmp.match(s);

	return 0;
}