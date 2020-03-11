#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true){
		int m; cin >> m;
		cin.ignore();
		if (m == 0) exit(0);

		string str; 
		int ans = -1;
		getline(cin, str);

		vector <int> memo(250, 0);
		bitset <250> mark; 

		int i = 0, j = 0;
		int mx = 0;

		while (i < str.length()){
			mark.set((int)str[i]);
			memo[(int)str[i]]++;
			mx++;

			if (mark.count() > m){
				while (j < i){
					memo[(int)str[j]]--;
					mx--;
					if (memo[(int)str[j]] == 0){
						mark.reset((int)str[j]);
						j++;
						break;
					}
					j++;
				}
			}

			ans = max(mx, ans);
			i++;
		}

		cout << ans << endl;
	}

	return 0;
}