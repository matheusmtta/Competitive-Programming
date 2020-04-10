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

vector <int> arr;
map <int, int> mp;
vector <vector<int>> ans;
int sum = 0;

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

	int t; cin >> t;

	while (t--){
		int n; cin >> n;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back(i);
			mp[i] = x;
			sum += x;
		}

		vector <int> emp;
		vector <int> rsp(n, 0);

		getsubs(emp, 0);

		for (int i = 0; i < ans.size(); i++){
			int tmp = 0;
			bitset<20> aux;
			for (int j = 0; j < ans[i].size(); j++){
				tmp += mp[ans[i][j]];
				aux[ans[i][j]] = 1;
			}

			if (tmp <= sum/2){
				for (int j = 0; j < n; j++){
					if (!aux[j] && tmp+mp[j] > sum/2)
						rsp[j]++;
				}
			}
		}

		for (int i = 0; i < n; i++)
			cout << "party " << i+1 << " has power index " << rsp[i] << endl;
		cout << endl;

		ans.clear();
		arr.clear();
		sum = 0;
	}

	return 0;
}