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

int64 fastExpRec(int64 a, int64 b){
	if (b == 0) return 1;
	
	int64 tmp = fastExpRec(a, b/2);
	int64 ans = tmp * tmp; 
	
	if (b & 1)
		return ans * a;

	return ans;
}

int64 fastExpIt(int64 a, int64 b){
	int64 ans = 1;

	while (b > 0){
		if (b & 1)
			ans = ans*a;
		a = a * a;
		b = b >> 1;
	}

	return ans;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64 a, b; cin >> a >> b;

	cout << fastExpRec(a, b) << endl;

	return 0;
}