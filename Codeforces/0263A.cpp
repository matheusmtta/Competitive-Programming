 
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define end "\n"
#define first f
#define second s
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;

	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			int x; cin >> x;
			if (x == 1){
				a = i;
				b = j;
			}
		}
	}

	cout << abs(2-a) + abs(2-b) << endl;

	return 0;
}
