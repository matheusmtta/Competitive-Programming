#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

char mtx[100][100];
int n;

bool check(int i, int j, char c){
	char curr = mtx[i][j];
	if (i != 1 && mtx[i-1][j] == c) return false;
	if (i != n && mtx[i+1][j] == c) return false;
	if (j != 1 && mtx[i][j-1] == c) return false;
	if (j != n && mtx[i][j+1] == c) return false;
	return true;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	int q = 1;

	while (cin >> n){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> mtx[i][j];
		cout << "Case " << q++ << ":" << endl;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (mtx[i][j] == '.'){
					for (int c = 'A'; c <= 'Z'; c++){
						if (check(i, j, c)) {
							mtx[i][j] = c;
							cout << mtx[i][j];
							break;
						}
					}
				}
				else cout << mtx[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}