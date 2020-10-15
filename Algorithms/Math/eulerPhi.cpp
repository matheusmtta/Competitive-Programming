#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

//Computes Phi(n) in O(sqrt(n))

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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int64 n;
	cin >> n;

	int64 ep = eulerPhi(n);

	return 0;
}