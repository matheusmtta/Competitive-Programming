#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

#define MAX 100000

typedef long long int int64;
typedef unsigned long long int  uint64;


//Given a integer sequence, finds the
//Longest Increasing Subsequence 
//LIS({-7, 10, 9, 2, 3, 8, 8, 1}) = {-7, 2, 3, 8}

//O(n^2) Approach
vector <int> dist(MAX, 1);
vector <int> parent(MAX, -1);
vector <int> subseq;

int pos = 0, n = 0;

vector <int> arr;

int LISQuadratic(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			if (arr[j] < arr[i] && dist[i] < dist[j]+1){
				dist[i] = dist[j]+1;
				parent[i] = j;
			}
		}
	}

	int ans = -1;
	
	for (int i = 0; i < n; i++){
		if (dist[i] > ans){
			ans = dist[i];
			pos = i;
		}
	}

	return ans;
}

void recover(){
	while (pos != -1){
		subseq.push_back(arr[pos]);
		pos = parent[pos];
	}

	reverse(subseq.begin(), subseq.end());
	
	for (auto k : subseq)
		cout << k << " ";
	cout << endl;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	arr = = {-7, 10, 9, 2, 3, 8, 8, 1};
	n = arr.size();

	cout << LISQuadratic() << endl;
	recoverLIS();

	return 0;
}