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

struct Trie {
	const static int alp = 10;
	char basis;

	int getID(char ch){
		return ch - basis;
	}

	struct Node {
		vector <int> next;
		bool leaf = false;
		Node(){
			next.resize(alp, -1);
		}
	};

	vector <int> pre, end;
	vector <Node> trie;

	Trie(char basis = 'a') : trie(1), pre(1), end(1), basis(basis) {};

	void addString(string s){
		int v = 0;
		for (char ch : s){
			int c = getID(ch);
			if (trie[v].next[c] == -1){
				trie[v].next[c] = trie.size();
				pre.push_back(0);
				trie.emplace_back();
			}
			v = trie[v].next[c];
			pre[v] += 1;
		}
		trie[v].leaf = true;
	}

	int find(string s){
		int v = 0;
		for (char ch : s){
			int c = getID(ch);
			v = trie[v].next[c];
			if (v == -1)
				return 0;
		}
		return v;
	}

	void erase(string s){
		int v = 0;
		for (char ch : s){
			int c = getID(ch);

			v = trie[v].next[c];
			pre[v]--;

			if (pre[trie[v].next[c]] == -1)
				trie[v].next[c] = -1;
		}
		trie[v].leaf = false;
	}

	int countPrefix(string s){
		return pre[find(s)];
	}
};

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector <string> s;
		Trie trie('0');
		for (int i = 0; i < n; i++){
			string str; cin >> str;
			s.push_back(str);
			trie.addString(str);
		}	
		bool flag = true;
		for (int i = 0; i < n; i++)
			if (trie.countPrefix(s[i]) > 1)
				flag = false;
		flag ? cout << "YES" << endl : cout << "NO" << endl;
	}

	return 0;
}