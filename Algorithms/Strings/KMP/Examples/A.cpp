#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

//given a misteryous string s "**a*..b**"
//and string t1 and t2, we must choose the
//'*' characters that give us a string s
//which oc(t1)-oc(t2) is maximum, and oc()
//defines the number of occurrences of ci
//in s.
//https://codeforces.com/contest/1163/problem/D

string s, t1, t2;
int memo[1010][60][60];
int check[1010][60][60];
vector <vector<int>> A;
vector <vector<int>> B;

struct KMP {
	string t;
	vector <int> pi;
	vector <vector<int>> aut;

	KMP(string t) : t(t+"$") {
		pi.resize(t.size()+1, 0);
		aut.resize(t.size()+1, vector<int>(27, 0));
		build();
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

	void build(){
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

	vector <int> match(string s){
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

int dp(int i, int j, int k){
	int ans = (t1.size() == j ? 1 : 0) - (t2.size() == k ? 1 : 0);
	if (i == s.size())
		return ans;

	int &curr = memo[i][j][k];

	if (check[i][j][k])
		return curr;

	check[i][j][k] = 1;

	if (s[i] == '*'){
		curr = -INF;
		for (int v = 0; v < 26; v++)
			curr = max(curr, ans + dp(i+1, A[j][v], B[k][v]));
	}
	else 
		curr = ans + dp(i+1, A[j][s[i]-'a'], B[k][s[i]-'a']);

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> t1 >> t2;

	A = KMP(t1).aut;
	B = KMP(t2).aut;

	memset(memo, 0, sizeof memo);
	memset(check, 0, sizeof check);

	cout << dp(0, 0, 0) << endl;

	return 0;
}