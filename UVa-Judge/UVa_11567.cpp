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

int64 solve(int n){
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n%2 == 0) return 1+solve(n/2);
	else return 1+min(solve(n+1), solve(n-1));
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64 n;
	while (cin >> n){
		cout << solve(n) << endl;
	}

	return 0;
}