 
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
		bool a = 1, b = 0, c = 1 , d = 1;
		int n, m; cin >> n >> m;

		if (n == 0 && m == 0) break; 

		vector <bitset<150>> vec(150);

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				int x; cin >> x;
				vec[i][j] = x;
			}
			if (vec[i].count() == m) a = 0;
			if (vec[i].count() == 0) d = 0;
		}

		bitset<150> tmp;
		bitset<150> tmp2;

		for (int i = 0; i < 150; i++)
			tmp2[i] = 1;

		for (int i = 0; i < n; i++){
			tmp |= vec[i];
			tmp2 &= vec[i];
		}

		if (tmp.count() == m) b = 1;
		if (tmp2.count() > 0) c = 0;

		cout << a+b+c+d << endl;
	}
	
	return 0;
}