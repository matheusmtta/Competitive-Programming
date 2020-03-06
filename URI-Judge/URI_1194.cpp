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

void build(string str1, string str2){
	char root = str1[0];
	int st = str2.find(root);

	if (st != 0)
		build(str1.substr(1, st), str2.substr(0, st));

	if (st+1 < str1.size())
		build(str1.substr(st+1), str2.substr(st+1));

	cout << root;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		string str1, str2; 
		cin >> str1 >> str2;

		build(str1, str2);
		cout << endl;
	}

	return 0;
}