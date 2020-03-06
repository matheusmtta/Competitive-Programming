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

	string str; cin >> str;

	int num = str[str.length()-1]-'0';
	uint64 sum = 0;

	for (int i = 0; i < str.length(); i++){
		sum += str[i]-'0';
	}

	cout << sum%3 << endl;

	return 0;
}