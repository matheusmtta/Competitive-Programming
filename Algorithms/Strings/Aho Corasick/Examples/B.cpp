#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

//2D AHO CORASICK https://www.spoj.com/problems/WPUZZLES/

#define f first
#define s second

const int alp = 60;

int n, m;
map <pair<int, int>, char> mp;
map <string, pair<pair<int, int>, char>> ans;

bool allow(int x, int y){
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	return true;
}

int get_id(char ch){
	if (ch >= 'A' && ch <= 'Z')
		return (ch - 'A') + 26;
	if (ch >= 'a' && ch <= 'z')
		return ch - 'a';
	return -1;
}

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
		return trie[v].go[chId];
	}

	void query(string s, pair<int, int> init, pair<int, int> move){
		int curr = 0;

	 	for (int i = 0; i < s.size(); i++){
	 		curr = go(curr, s[i]);
	 		if (trie[curr].leaf){
	 			int sz = (int)trie[curr].word.size();
	 			int a = init.f + (i - sz + 1)*move.f;
	 			int b = init.s + (i - sz + 1)*move.s;
	 			ans[trie[curr].word] = {{a, b}, mp[move]};
	 		}
	 	}
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	mp[{-1, 0}] = 'A'; mp[{-1, 1}] = 'B'; mp[{0, 1}] = 'C'; mp[{1,  1}] = 'D';
	mp[{1,  0}] = 'E'; mp[{1, -1}] = 'F'; mp[{0,-1}] = 'G'; mp[{-1,-1}] = 'H'; 

	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		int q; cin >> q;
		
		ahoCorasick ac;

		vector <string> puzz;
		for (int i = 0; i < n; i++){
			string str; cin >> str;
			puzz.push_back(str);
		}

		vector <string> words;
		for (int i = 0; i < q; i++){
			string str; cin >> str;
			ac.addString(str);
			words.push_back(str);
		}

		vector <pair<int, int>> dir = {{-1, 0},  //A
									   {-1, 1},  //B
									   {0,  1},  //C
									   {1,  1},  //D
									   {1,  0},  //E
									   {1, -1},  //F
									   {0, -1},  //G
									   {-1,-1}}; //H

		int mv = 0;

		vector <pair<int, int>> move = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

		pair <int, int> pos = {0, 0};
		bool flag = false;

		while (1){
			if (pos.f == 0 && pos.s == 0 && flag) break;
			flag = true;

			for (int u = 0; u < 8; u++){
				string curr;
				for (int i = pos.f, j = pos.s;; i += dir[u].f, j += dir[u].s){
					if (allow(i, j))
						curr += puzz[i][j];
					else
						break;
				}
				ac.query(curr, pos, dir[u]);
			}

			if (pos.f == n-1 && pos.s ==   0) mv++;
			if (pos.f == n-1 && pos.s == m-1) mv++;
			if (pos.f ==   0 && pos.s == m-1) mv++;

			pos.f += move[mv].f;
			pos.s += move[mv].s;
		}

		for (int i = 0; i < (int)words.size(); i++)
			cout << ans[words[i]].f.f << " " << ans[words[i]].f.s << " " << ans[words[i]].s << endl;

		if (t) cout << endl;
	}

	return 0;
}
