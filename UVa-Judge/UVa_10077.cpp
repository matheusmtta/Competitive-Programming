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

	while (true){
		int m, n; cin >> m >> n;
		
		if (m == 1 && n == 1)
			break;

		pair <int, int> nd, lst_left, lst_right;

		lst_left.first = 0;
		lst_left.second = 1;
		lst_right.first = 1;
		lst_right.second = 0;
		
		while (true){
			nd.first = lst_left.first + lst_right.first;
			nd.second = lst_left.second + lst_right.second;
			//cout << nd.first << " " << nd.second << endl;
			if (m == nd.first && n == nd.second)
				break;
			if (nd.first * n > nd.second * m){
				cout << "L";
				lst_right = nd;
			}
			else {
				cout << "R";
				lst_left = nd;
			}
		}
		cout << endl;
	}	

	return 0;
}