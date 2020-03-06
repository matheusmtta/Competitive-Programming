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

	string str1, str2;
	cin >> str1;
	cin >> str2;

	int count = 0;

	for (int i = 0; i < str1.length()-str2.length()+1; i++){
		bool ans = true;
		for (int j = 0; j < str2.length(); j++){
			if (str1[i+j] == str2[j]) {ans = false; break;}
		}
		if (ans) count++;
	}

	cout << count << endl;

	return 0;
}