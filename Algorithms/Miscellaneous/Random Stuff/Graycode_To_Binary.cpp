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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n, k;
		cin >> n >> k;

		//TAKE THE K^TH GRAY CODE NUMBER
		//TO ITS RESPECTIVE BINARY FORM

		//EXAMPLE
		//LETS TAKE THE GRAY CODE NUMBER G3, G2, G1, G0

		/*
		.| GRAY CODE   G3      G2      G1      G0
		.|	  		   |     /        /      /
		.|	     	   |	XOR     XOR    XOR
		.|             |   /       /      /
		.|             |  /		  /      /
		.| BINARY      B3      B2      B1      B0
		*/

		/*
		.| B3 = G3
		.| B2 = B3 XOR G2
		.| B1 = B2 XOR G1
		.| B0 = B1 XOR G0
		.|
		.| SO ITS SIMPLY TAKE B(K) = K^(K >> 1)
		.| WHERE WE SHIFT THE K GRAY CODE NUMBER
		.| ONE BIT TO RIGHT.
		*/

		/*
		.| GRAY CODE   1      0        0      1
		.|	  		   |     /        /      /
		.|	     	   |	XOR     XOR    XOR
		.|             |   /       /      /
		.|             |  /		  /      /
		.| BINARY      1         1      1      0
		.|
		.| B3 = G3 = 1
		.| B2 = B3 XOR G2 = 1
		.| B1 = B2 XOR G1 = 1
		.| B0 = B1 XOR G0 = 0
		.|
		.| B(1001) = 1110
		*/

		int ans = k^(k >> 1);

		cout << ans << endl;
	}

	return 0;
}


//REFERENCE: https://testbook.com/blog/conversion-from-gray-code-to-binary-code-and-vice-versa/