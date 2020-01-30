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
	int n; 
	cin >> n;
	int vec[n+1];

	for (int i = 1; i <= n; i++){
		int x; cin >> x; vec[x] = i;
	}

	for (int i = 1; i <= n; i++)
		cout << vec[i] << " ";
	cout << endl;
}