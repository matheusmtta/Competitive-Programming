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

vector <int64> basis;

const uint64 MAX = 1LL << 32;

void build(){
	for (int i = 0; i <= 32; i++){
		for (int j = 0; j <= 32; j++){
			int64 a = pow(2, i)*pow(3, j);
			if (a < MAX)
				basis.push_back(a);
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	build();

	sort(basis.begin(), basis.end());
	
	while (true){
		int64 n; cin >> n;
		if (n == 0) break;

		int l = 0, r = basis.size()-1;

		int64 ans;

		while (l <= r){
			int mid = (l+r+1)/2;
			
			if (basis[mid] < n)
				l = mid + 1;
			else {
				ans = basis[mid];
				r = mid - 1;
			}
		}

		cout << ans << endl;
	}

	return 0;
}