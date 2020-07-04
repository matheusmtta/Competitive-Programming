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

	int a;

	while (cin >> a){
		vector <int> b; 
		b.push_back(-1);
		b.push_back(a);
		
		bool flag = false;

		for (int i = 1; i < 6; i++){
			int x; cin >> x;
			if (x != 0) flag = true;
			b.push_back(x);
		}

		if (!flag) return 0;

		int ans = 0;

		ans += b[6]; //6X6
		ans += b[5]; //5x5
		b[1] -= 11*b[5];
		ans += b[4];  //4x4
		//if (5*b[4] - b[2] > 0)
		//	b[1] -= 4*(5*b[4] - b[2]);
		b[2] -= 5*b[4];
		ans += b[3]/4; //3X3
		b[3]%=4;

		//remaining 3 parcel
		if (b[3] != 0){
			ans++;
			if (b[3] == 1){
				b[2] -= 5;
				b[1] -= 7;
			}
			if (b[3] == 2){
				b[2] -= 3;
				b[1] -= 6;
			}
			if (b[3] == 3){
				b[2] -= 1;
				b[1] -= 5;
			}
		}
		if (b[2] > 0){
			ans += b[2]/9;
			if (b[2]%9 > 0){
				ans ++;
			}
			b[1] -= 36 - ((b[2]%9)*4);
		}
		else if (b[2] < 0){
			b[1] -= (-b[2])*4;
		}
		if (b[1] > 0){
			ans += b[1]/36;
			if (ans%36 > 0) ans++;
		}

		cout << ans << endl;
	}

	return 0;
}