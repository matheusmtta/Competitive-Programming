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

int t, c, jok;

double rec(int idx, int sum){
	if (idx == jok && sum == t) return 1;
	if (idx == jok) return 0;
	return rec(idx+1, sum+1) + rec(idx+1, sum-1);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b; cin >> a >> b;
	
	jok = 0;
	vector <int> arr(2, 0);

	c = 0, t = 0;

	for (auto x : a) x == '+' ? t++ : t--;
	for (auto x : b) {
		if (x == '?') jok++;
		if (x == '+') c++;
		if (x == '-') c--;
	}
	
	cout << setprecision(10) << rec(0, c)/((double)(1 << jok)) << endl;

	return 0;
}