#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		string str; cin >> str;
		vector <int> subseq;
		int i = 0;
		while (i < str.size()){
			int l = i, r = i;
			if (str[i] == '1'){
				while (str[i] == '1'){
					i++;
				}
				r = i;
				subseq.push_back(r-l);
			}
			i++;
		}
		sort(subseq.begin(), subseq.end());
		reverse(subseq.begin(), subseq.end());
		int ans = 0;
		for (int i = 0; i < subseq.size(); i+=2)
			ans += subseq[i];
		cout << ans << endl;
	}	

	return 0;
}