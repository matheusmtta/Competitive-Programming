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
	while (true){
		string str; cin >> str;
		if (str == "#") return 0;

		if (next_permutation(str.begin(), str.end())){
			cout << str << endl;
		}
		else cout << "No Successor" << endl;
	}
	
	return 0;
}