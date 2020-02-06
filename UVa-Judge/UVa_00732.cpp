#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void backtrack(string &a, string &b, int i, int j, vector <char> &ans, stack <char> &tt){
	if (j == b.size()){
		for (int k = 0; k < ans.size(); k++){
			cout << ans[k];
			if (k != ans.size() - 1) cout << " ";
		}
		cout << endl;
		return;
	}
	if (i < b.size()){
		ans.push_back('i');
		tt.push(a[i]);
		backtrack(a, b, i+1, j, ans, tt);
		ans.pop_back();
		tt.pop();
	}
	if (!tt.empty() && tt.top() == b[j]){
		ans.push_back('o');
		char aux = tt.top();
		tt.pop();
		backtrack(a, b, i, j+1, ans, tt);
		ans.pop_back();
		tt.push(aux);
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;

	while (cin >> a){
		cin >> b;
		cout << '[' << endl;
		vector <char> ans;
		stack <char> tt;
		int i = 0, j = 0;
		backtrack(a, b, i, j, ans, tt);
		cout << "]" << endl;
	}

	return 0;
}


//credits: https://github.com/KHvic/uva-online-judge/blob/master/732-Anagrams%20by%20Stack.cpp