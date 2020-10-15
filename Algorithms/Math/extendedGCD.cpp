#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

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

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64 a, b, s, t;

    int64 d = gcdExtend(a, b, s, t);

    return 0;
}