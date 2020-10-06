#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

//compute a^b in O(logn) :3

int64 fastExp(int64 a, int64 b){
	if (b == 0)
		return 1;
	int64 ans = fastExp(a, b/2);
	if (b & 1)
		return ans * ans * a;
	else
		return ans * ans; 
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64 a, b; cin >> a >> b;

	cout << fastExp(a, b) << endl;

	return 0;
}