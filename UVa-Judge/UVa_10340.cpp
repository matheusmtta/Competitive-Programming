#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s, t; 

	while (cin >> s >> t){
		int ans = 0;
		int j = 0;
		for (int i = 0; i < t.size(); i++){
			if (ans >= s.size()) break;
			if (s[ans] == t[i]) 
				ans++;
		}

		ans == s.size() ? cout << "Yes" << endl : cout << "No" << endl;
	}

	return 0;
}