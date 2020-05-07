#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

//Time complexity: O(logN)

int N;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector <int> arr;

	int ans, ub, lb;

	//Search for N in a array

	int l = 0, r = arr.size()-1;

	while (l <= r){
		int mid = l+r/2;
		if (arr[mid] == N){
			ans = mid;
			break;
		}
		else if (arr[mid] < N) 
			l = mid + 1;
		else
			r = mid - 1;
	}

	l = 0, r = arr.size()-1;

	//Lower Bound (greatest element stricly smaller or equal than N)
	while (l <= r){
		int mid = l+r/2;
		if (arr[mid] > N) 
			r = mid-1;
		else {
			lb = mid;
			l = mid + 1;
		}
	}

	l = 0, r = arr.size()-1;

	//Upper Bound (smallest element strictly greater or equal than N)
	while (l <= r){
		int mid = l+r/2;
		if (arr[mid] < N)
			l = mid + 1;
		else {
			ub = mid;
			r = mid - 1;
		}
	}

	return 0;
}