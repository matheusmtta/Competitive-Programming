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

int choices[9999999];

bool allow(int k){
	int r = k%10;
	int disc[10] = {0};

	while (k != 0){
		if (disc[r] || r == 0) return false;
		disc[r] = 1;
		k /= 10;
		r = k%10;
	}
	return true;
}

int find(int x){
	if (!allow(x)) 
		return false;

	string tmp = to_string(x);

	int n = tmp.length();

	int v[n] = {0};

	int pos = 0;
	int count = 0;

	while (count < n){
		if (v[pos]) return false;
			
		int nx = tmp[pos]-'0';
		v[pos]++;
		pos = (pos+nx)%n;

		count++;
	}

	if (pos != 0) return false;
	return true;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q = 1;

	for (int i = 9876543; i > 9; i--){
		if (find(i))
			choices[i] = i;
		else
			choices[i] = choices[i+1];
	}

	while (cin >> n){
		if (n == 0) exit(0);
		cout << "Case " << q << ": ";

		cout << choices[n] << endl;

		q++;
	}

	return 0;
}