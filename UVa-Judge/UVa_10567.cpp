#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
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

	int n; cin >> n;

	while (n--){
		string s; cin >> s;
		
		int ans = 0;
		int lst = 0, mn = INF, mx = -1;

		for (int i = 0; i < s.size(); i++){
			for (int j = lst; j < str.size(); j++){
				if (s[i] == str[j]){
					ans++;
					mn = min(j, mn);
					mx = max(j, mx);
					lst = j+1;
					break;
				}
			}
		}

		ans == s.size() ? cout << "Matched " << mn << " " << mx << endl : cout << "Not matched" << endl;
	}

	return 0;
}