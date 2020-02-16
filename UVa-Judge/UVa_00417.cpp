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
	

map <string, int> mp;
int s = 1;


void build(string str, int len){
	if (str.length() == len){
		mp[str] = s;
		s++;
		return;
	}

	char lst;

	if (str.empty())
		lst = 'a';
	else
		lst = str[str.size()-1] + 1;

	for (char c = lst; c <= 'z'; c++)
		build(str + c, len);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 5; i++)
		build("", i);

	string str;

	while (cin >> str){
		cout << mp[str] << endl;
	}

	return 0;
}