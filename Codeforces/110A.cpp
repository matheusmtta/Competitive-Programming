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
	string n; cin >> n;
	uint64 m = 0;

	for (int i = 0; i < n.length(); i++){
		if (n[i] == '4' || n[i] == '7') m++;
	}

	string str = to_string(m);

	int64 ans = 0;

	for (int i = 0; i < str.length(); i++){
		if (str[i] == '4' || str[i] == '7') ans++;
	}

	if (ans == str.length()) cout << "YES" << endl;
	else cout << "NO" << endl;
}