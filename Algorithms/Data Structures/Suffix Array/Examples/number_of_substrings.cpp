#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back
 
typedef long long int int64;
typedef unsigned long long int  uint64;
 
int n;
string str;
vector <int> pos;
vector <int> equivC;
vector <pair<char, int>> arr;
 
void radixSort(){
	vector <int> count(n);
 
	for (int x : equivC)
		count[x]++;
 
	vector <int> aux(n);
	vector <int> idx(n);
 
	idx[0] = 0;
 
	for (int i = 1; i < n; i++)
		idx[i] = idx[i - 1] + count[i - 1];
 
	for (auto x : pos){
		int j = equivC[x];
		aux[idx[j]] = x;
		idx[j]++;
	}
 
	pos = aux;
}
 
void init(){
	pos.resize(n); arr.resize(n); equivC.resize(n);
 
	for (int i = 0; i < n; i++)
		arr[i] = {str[i], i};
 
	sort(arr.begin(), arr.end());
 
	for (int i = 0; i < n; i++)
		pos[i] = arr[i].second;
 
	equivC[pos[0]] = 0;
	for (int i = 1; i < n; i++){
		if (arr[i].first == arr[i-1].first)
			equivC[pos[i]] = equivC[pos[i-1]];
		else
			equivC[pos[i]] = equivC[pos[i-1]] + 1;
	}
}
 
void build(){
	int k = 0;
 
	while ((1 << k) < n){
		for (int i = 0; i < n; i++)
			pos[i] = (pos[i] - (1 << k) + n)%n;
 
		radixSort();
 
		vector <int> aux(n);
 
		aux[pos[0]] = 0;
		for (int i = 1; i < n; i++){
			pair <int, int> prev = {equivC[pos[i - 1]], equivC[(pos[i - 1] + (1 << k))%n]};
			pair <int, int> nxt = {equivC[pos[i]], equivC[(pos[i] + (1 << k))%n]};
			if (prev == nxt)
				aux[pos[i]] = aux[pos[i - 1]];
			else 
				aux[pos[i]] = aux[pos[i - 1]] + 1;
		}
 
		equivC = aux;
		k++;
	}
}
 
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> str;
	str = str + "$";
 
	n = str.size();
 
	init();
	build();
 
	int t; cin >> t;
	while (t--){
		string curr; cin >> curr;
 
		int r = n, l = 0, idx_mn = INF;
		int ans = 0;
		bool flag = false;
 
		while (l <= r){
			int mid = (l + r)/2;
			
			if (mid >= n || mid < 0)
				break;
			
			string prefix = str.substr(pos[mid], curr.size());
			if (prefix == curr){
				idx_mn = min(mid, idx_mn);
				r = mid - 1;
				flag = true;
				continue;
			}
			if (prefix < curr)
				l = mid + 1;
			else
				r = mid - 1;
		}

		if (idx_mn == INF)
			idx_mn = 0;
 
 		r = n, l = 0;
		int idx_mx = 0;

		while (l <= r){
			int mid = (l + r)/2;
			
			if (mid >= n || mid < 0)
				break;
			
			string prefix = str.substr(pos[mid], curr.size());
			if (prefix == curr){
				idx_mx = max(mid, idx_mx);
				l = mid + 1;
				continue;
			}
			if (prefix < curr)
				l = mid + 1;
			else
				r = mid - 1;
		}

		if (flag) cout << min(idx_mx, n-1) - idx_mn + 1 << endl;
		else cout << 0 << endl;
	}
 
	return 0;
}