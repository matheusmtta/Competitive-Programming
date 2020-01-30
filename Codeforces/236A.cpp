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
	
int aux[26];
int ans = 0;

int main(){
	string str; cin >> str;

	for (int i = 0; i < str.length(); i++){
		aux[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++){
		if (aux[i])
			ans++;
	}

	cout << ans << endl;

	if (ans%2 == 1) cout << "IGNORE HIM!" << endl;
	else cout << "CHAT WITH HER!" << endl; 
}