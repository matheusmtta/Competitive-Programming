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

//Maximum 1D Range Sum O(n)

int MaxRangeSum1D(){
 	int n; cin >> n;
 	vector <int> arr;

 	int ans = -INF, sum = 0;

 	for (int i = 0; i < n; i++){
 		int x; cin >> x;
 		arr.push_back(x);
 	}

 	for (int i = 0; i < n; i++){
 		sum += arr[i];
 		ans = max(sum, ans);
 		if (sum < 0) sum = 0;
 	}

 	return ans;
}

//Maximum 2D Range Sum O(n^4)

int MaxRangeSum2D(){
	int n; cin >> n;
	vector <vector<int>> matrix(n, vector<int> (n));

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> matrix[i][j];
			if (i > 0) matrix[i][j] += matrix[i-1][j];
			if (j > 0) matrix[i][j] += matrix[i][j-1];
			if (i > 0 && j > 0) matrix[i][j] -= matrix[i-1][j-1];
		}
	}

	int ans = -INF;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int r = i; r < n; r++){
				for (int c = j; c < n; c++){
					int submtx = matrix[r][c]; //sum from (0, 0) to (r, c)
					if (i > 0) submtx -= matrix[i-1][c];
					if (j > 0) submtx -= matrix[r][j-1];
					if (i > 0 && j > 0) submtx += matrix[i-1][j-1];
					ans = max(ans, submtx);
				}
			}
		}
	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	MaxRangeSum1D();
	MaxRangeSum2D();

	return 0;
}