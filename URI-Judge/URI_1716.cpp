#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

#define MAX 50000

typedef long long int int64;
typedef unsigned long long int  uint64;

int64 n, e, c;

int64 eulerPhi(int64 n) {
    int64 ans = n;
    for (int64 i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            ans -= ans / i;
        }
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}

int64 gcdExtend(int64 a, int64 b, int64& s, int64& t) {
    if (b == 0) {
        s = 1;
        t = 0;
        return a;
    }
    int64 s1, t1;
    int64 d = gcdExtend(b, a % b, s1, t1);
    s = t1;
    t = s1 - t1 * (a/b);
    return d;
}

int64 fastExp(int64 a, int64 b){
	int64 ans = 1;

	while (b > 0){
		if (b & 1)
			ans = (ans*a)%n;
		
		a = (a * a)%n;

		b = b >> 1;
	}

	return ans;
}

int64 modularInverse(int64 a, int64 m){
	int64 s, t;
	int64 d = gcdExtend(a, m, s, t);
	return s = (s % m + m) % m;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> e >> c;

	int64 ep = eulerPhi(n);
	int64 exp = modularInverse(e, ep);

	cout << fastExp(c, exp) << endl;

	return 0;
}