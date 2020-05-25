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
	int n; cin >> n;
	while (n--){
		string str; cin >> str;
		if (str.length() > 10)
			cout << str[0] << str.length()-2 << str[str.length()-1] << endl;
		else cout << str << endl;
	}
}