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

int flag1 = 0, flag2 = 0;
	
int64 getmin(vector <int64> arr, string op){
	while (flag2 > 0){
		int64 mn = LINF, idx = 0, skip = 0;
		for (int i = 0; i < op.size(); i++){
			if (op[i] == '*' && mn > arr[i]*arr[i+1]){
				idx = i;
				skip = i+1;
				mn = arr[i]*arr[i+1];
			}
		}
		arr[idx] = mn;
		string aux = "";
		for (int i = 0; i < op.size(); i++){
			if (i != idx)
				aux += op[i];
		}
		op = aux;
		vector <int64> tmp;
		for (int i = 0; i < arr.size(); i++){
			if (i != skip)
				tmp.push_back(arr[i]);
		}
		arr = tmp;
		flag2--;
	}
	int64 rsp = 0;
	
	for (auto k : arr)
		rsp += k;

	return rsp;
}

int64 getmax(vector <int64> arr, string op){
	while (flag1 > 0){
		int64 mn = LINF, idx = 0, skip = 0;
		for (int i = 0; i < op.size(); i++){
			if (op[i] == '+' && mn > arr[i]+arr[i+1]){
				idx = i;
				skip = i+1;
				mn = arr[i]+arr[i+1];
			}
		}
		arr[idx] = mn;
		string aux = "";
		for (int i = 0; i < op.size(); i++){
			if (i != idx)
				aux += op[i];
		}
		op = aux;
		vector <int64> tmp;
		for (int i = 0; i < arr.size(); i++){
			if (i != skip)
				tmp.push_back(arr[i]);
		}
		arr = tmp;
		flag1--;
	}
	int64 rsp = 1;

	for (auto k : arr)
		rsp *= k;

	return rsp;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		string str; cin >> str;
		vector <int64> arr;
		string op;
		flag1 = flag2 = 0;
		string curr;
		for (int i = 0; i < str.size(); i++){
			if (str[i] == '+' || str[i] == '*'){
				op += str[i];
				arr.push_back(stoi(curr));
				curr = "";
				if (str[i] == '+') flag1 += 1;
				if (str[i] == '*') flag2 += 1;
			}
			else curr += str[i];
		}
		arr.push_back(stoi(curr));

		int64 ans1 = 0, ans2 = 0;

		ans1 = getmin(arr, op);
		ans2 = getmax(arr, op);

		cout << "The maximum and minimum are " << ans2 << " and " << ans1 << "." << endl;
	}

	return 0;
}