#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1620
//Find which patterns t occur in s

int get_id(char ch){
	if (ch >= 'A' && ch <= 'Z')
		return (ch - 'A') + 26;
	if (ch >= 'a' && ch <= 'z')
		return ch - 'a';
	return -1;
}

const int MAX = 1010;
const int alp = 60;

map <string, int> mp;

struct ahoCorasick {
	struct node {
		vector <int> next;
		vector <int> go;
		int p = -1, link = -1;
		bool leaf = false;
		char ch;
		string word;

		node(int p = -1, char ch = '$') : p(p), ch(ch) {
			next.resize(alp, -1);
			go.resize(alp, -1);
		}  
	};

	vector <node> trie;

	ahoCorasick() : trie(1) { }

	void addString(string s){
		int v = 0;
		for (char c : s){
			int chId = get_id(c);
			if (trie[v].next[chId] == -1){
				trie[v].next[chId] = trie.size();
				trie.emplace_back(v, c);
			}
			v = trie[v].next[chId];
		}
		trie[v].word = s;
		trie[v].leaf = true;
	}

	int getLink(int v){
		if (trie[v].link == -1){
			if (v == 0 || trie[v].p == 0)
				trie[v].link = 0;
			else
				trie[v].link = go(getLink(trie[v].p), trie[v].ch);
		}
		return trie[v].link;
	}

	int go(int v, char c){
		int chId = get_id(c);
		if (trie[v].go[chId] == -1){
			if (trie[v].next[chId] != -1)
				trie[v].go[chId] = trie[v].next[chId];
			else
				trie[v].go[chId] = v == 0 ? 0 : go(getLink(v), c);
		}
		if (trie[trie[v].go[chId]].leaf) mp[trie[trie[v].go[chId]].word] = 1;
		return trie[v].go[chId];
	}

	void query(string s){
		int curr = 0;

		for (int i = 0; i < s.size(); i++)
			curr = go(curr, s[i]);
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		int q; cin >> q;
		
		ahoCorasick ac;

		vector <string> arr;

		for (int i = 0; i < q; i++){
			string t; cin >> t;
			ac.addString(t);
			arr.push_back(t);
			mp[t] = 0;
		}

		ac.query(s);
		
		for (int i = 0; i < q; i++){
			if (mp[arr[i]])
				cout << "y" << endl;
			else
				cout << "n" << endl;
		}
		mp.clear();
	}

	return 0;
}