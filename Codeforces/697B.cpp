#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		int64 n; cin >> n;
		
		if (n < 2020) {cout << "NO" << endl; continue;}
		
		int b = n%2020;
		int a = n/2020 - b;

		if (a >= 0 && b >= 0 && a*2020 + b*2021 == n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}