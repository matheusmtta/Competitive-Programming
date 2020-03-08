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
	
set <uint64> f;

void is_despo(int64 num){
	uint64 e = 2;

	while (e*e <= num){
		while (num%e==0){
			f.insert(e);
			num/=e;
		}
		e++;
	}

	if (num != 1) f.insert(num);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	uint64 n;
	cin >> n;

	is_despo(n);

	cout << (1ll << f.size())-f.size()-1 << endl;

	return 0;
}