#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){
	int32 R, Q, C;

	int32 t, q = 1; cin >> t;

	while (t--){
		cin >> C >> R;
		set <int32> ans;

		cout << "Case #" << q << ":";
		if (R == C) {cout << " 0" << endl; q++; continue;}


		for (int32 i = 1; i*i <= (C-R); i++){
			if ((C-R)%i == 0) {ans.insert(i); ans.insert((C-R)/i);}
		}

		
		set <int32>::iterator it;

		for (it = ans.begin(); it != ans.end(); it++){
			if (*it > R) cout << " " << *it;
		}

		cout << endl;
		q++;
	}
	
	return 0;
}