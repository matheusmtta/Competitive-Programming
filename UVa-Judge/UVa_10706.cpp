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

vector <int64> seqlen;
string basis;

void build(){
	seqlen.push_back(0);
	int64 len = 0, sz = 0;

	for (int i = 1; seqlen[i-1] <= 2147483647; i++){
		len = (int)log10(i)+1;
		basis += to_string(i);
		sz += len;
		seqlen.push_back(sz + seqlen[i-1]); 
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	build();

	int t; cin >> t;

	while (t--){
		int l, r;
		l = 0, r = seqlen.size()-1;

		int64 s, ans; cin >> s;

		while (l <= r){
			int mid = (l + r)/2;

			if (seqlen[mid] >= s)
				r = mid-1;
			else {
				l = mid+1;
				ans = seqlen[mid];
			}
		}

		int64 aux = s - ans;

		cout << basis[aux-1] << endl;
	}

	return 0;
}