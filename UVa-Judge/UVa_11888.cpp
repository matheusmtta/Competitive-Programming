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

bool isPalindrome(string s){
	if (s == "") return false;
	for (int i = 0; i < s.size()/2; i++)
		if (s[i] != s[s.size()-i-1])
			return false;
	return true;
}

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
	vector <int> ans;
	for (int i = 0, j = 0; i < s.size(); i++){
		while (j > 0 && s[i] != t[j])
			j = pi[j-1];
		if (s[i] == t[j])
			j++;
		if (j+1 == t.size()){
			ans.push_back(i - j + 1);
		}
	}
	
	if (ans.size() == 0) return -1;
	return ans[ans.size()/2];
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		string str; cin >> str;
		string s = str + str;

		string t = str; 
		reverse(t.begin(), t.end());
	
		prefix_function(t);
		int idx = match(s, t);
		
		if (idx == -1)
			cout << "simple" << endl;
		else {
			string a = s.substr(0, idx);
			string b = s.substr(idx+str.size(), s.size());

			if (isPalindrome(a) && isPalindrome(b))
				cout << "alindrome" << endl;
			else if (isPalindrome(str))
				cout << "palindrome" << endl;
			else
				cout << "simple" << endl; 
		}
 	}

	return 0;
}