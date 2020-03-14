#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;  

int N, C, T;	
vector <int64> popcorn(100100, 0);
int64 sum;
int64 mx = -1; 

bool verify(int64 q){
	int64 k = T*q;
	int64 count = 0;

    if (k < mx) return false;

	int c = 0;

	for (int i = 0; i < N; i++){
		if (count + popcorn[i] > k){
			c++;
			count = 0;
		}
		count += popcorn[i];
	}

	if (count > k) return false;
    if (count != 0) c++;
    
	if (c <= C) return true;
	return false;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C >> T;
	int64 sum = 0;
	for (int i = 0; i < N; i++){
		cin >> popcorn[i];
		sum += popcorn[i];
		mx = max(mx, popcorn[i]);
	}

	int64 i = 0, j = sum+100;
	int64 ans = j;

	while (i <= j){
		int64 m = (i+j)/2;
		bool qry = verify(m);

		if (qry){
			ans = min(m, ans);
			j = m-1;
		}
		else i = m+1;
	}

	cout << ans << endl;

	return 0;
}