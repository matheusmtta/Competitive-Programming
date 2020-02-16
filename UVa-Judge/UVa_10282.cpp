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


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;

	map <string, string> mp;

	bool flag = false;

	while (getline(cin, str)){
		string a, b;
		if (str == "") break;
		int i  = 0;
		flag = false;
		while(i < str.length()){
			if (str[i] == ' ') {flag = true; i++;}
			if (!flag) a += str[i];
			else b += str[i];
			i++;
		}

		mp[b] = a;
	}
	
	string tmp;

	while (cin >> tmp){
		if (mp.find(tmp) == mp.end()) cout << "eh" << endl;
		else cout << mp[tmp] << endl;
	}

	return 0;
}