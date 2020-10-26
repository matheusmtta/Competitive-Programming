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

//Maximum 2D Range Sum O(n^3)

int MaxRangeSum1D(vector <int> arr){
	int n = arr.size();

 	int ans = -INF, sum = 0, tmp = 0, l = 0, r = 0;

 	for (int i = 0; i < n; i++){
 		sum += arr[i];
 		if (sum < 0){ 
 			sum = 0;
 			tmp = i + 1;
 		}
 		else if (sum > ans) {
 			ans = max(sum, ans);
 			l = tmp;
 			r = i;
 		}
 	}

 	return ans;
}


int MaxRangeSum2D(){
	int n, m; cin >> n >> m;
	vector <vector<int>> matrix(n+1, vector<int> (m+1, 0));

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> matrix[i][j];
			matrix[i][j] += matrix[i][j-1];
		}
	}

	int ans = -INF;

	for (int i = 1; i <= m; i++){
		vector <int> aux(n+1, 0);
		for (int j = i; j <= m; j++){
			for (int k = 1; k <= n; k++)
				aux[k] = matrix[k][j] - matrix[k][i-1];
			ans = max(MaxRangeSum1D(aux), ans);
		}
	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	MaxRangeSum2D();

	return 0;
}