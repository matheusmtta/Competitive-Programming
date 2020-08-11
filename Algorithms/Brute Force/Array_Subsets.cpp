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

//Get all 2^n elements subsets of a array in O(2^n) 

vector <int> arr;
vector <vector<int>> ans;

void getsubs(vector <int> &subs, int idx){
	ans.push_back(subs);

	for (int i = idx; i < arr.size(); i++){
		subs.push_back(arr[i]);
		getsubs(subs, i+1);
		subs.pop_back();
	}

	return;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	for (int i = 0; i < n; i++){
		int x; cin >> x;
		arr.push_back(i);
	}

	vector <int> emp;

	getsubs(emp, 0);

	return 0;
}