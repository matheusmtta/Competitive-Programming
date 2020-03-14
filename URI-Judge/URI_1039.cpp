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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int X, x, Y, y, R, r;
	float dist;
	while (scanf("%d %d %d %d %d %d", &R,&X,&Y,&r,&x,&y) != EOF){
		dist = sqrt(pow((X-x), 2)+pow((Y-y), 2));

		if (R >= r+dist) cout << "RICO" << endl;
		else cout << "MORTO" << endl;
	}

	return 0;
}