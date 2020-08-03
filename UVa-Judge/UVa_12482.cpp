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

	int N, L, C;

	while (cin >> N >> L >> C){
		int ans = 1, l = 0, c = 0;
		for (int i = 0; i < N; i++){
			string str; cin >> str;
			if (c + str.length() <= C) 
				c += str.length()+1;
			else {
				l++;
				if (l == L){
					l = 0;
					ans++;
				}
				c = str.length()+1;
			}
		}
		//cout << "-> " << l << " " << c << endl;
		cout << ans << endl;
	}

	return 0;
}