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
	string a, b, c, d;
	cin >> a >> b >> c;

	d = a + b;

	sort(d.begin(), d.end());
	sort(c.begin(), c.end());

	if (d == c) cout << "YES" << endl;
	else cout << "NO" << endl;
}