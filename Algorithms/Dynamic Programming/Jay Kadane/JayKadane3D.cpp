#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back
#define MAX 30

typedef long long int int64;
typedef unsigned long long int  uint64;

int64 block[MAX][MAX][MAX];
int a, b, c;
int64 zero = 0;

int64 MaxRangeSum3D(){
	cin >> a >> b >> c;

    memset(block, 0, sizeof block);

    int64 flag = -LINF;

    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            for (int k = 1; k <= c; k++){
                cin >> block[i][j][k];
                flag = max(block[i][j][k], flag);
                block[i][j][k] += block[i][j][k-1];
                block[i][j][k] += block[i][j-1][k];
                block[i][j][k] -= block[i][j-1][k-1];
            }
        }
    }

    int64 ans = 0;

    for (int i = 1; i <= b; i++){
        for (int j = 1; j <= c; j++){
            for (int l = i; l <= b; l++){
                for (int r = j; r <= c; r++){
                    int64 curr = 0;
                    for (int k = 1; k <= a; k++){
                        int64 submtx = block[k][l][r]   - 
                                       block[k][i-1][r] -
                                       block[k][l][j-1] +
                                       block[k][i-1][j-1];
                        curr = max(curr + submtx, zero);
                        ans = max(ans, curr);
                    }
                }
            }
        }
    }

    return ans;
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       
    MaxRangeSum3D();

    return 0;
}