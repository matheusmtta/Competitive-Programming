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

bool compare(const pair <string, int> &a, pair <string, int> &b){
	return a.second > b.second;
}

bool is_pal(string str){
	int i = 0; int j = str.length()-1;

	while (i < j){
		if (str[i] != str[j]) return false;
		i++;
		j--;
	}
	return true;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector <string> arr;
	vector <string> middle;
	map <string, int> subpal;

	string ans;

	for (int i = 0; i < n; i++){
		string tmp; cin >> tmp;
		vector <string>::iterator it;

		if (is_pal(tmp)){
			it = find(middle.begin(), middle.end(), tmp);
			if (it != middle.end()){
				middle.erase(it);
				subpal[tmp]++;
			}
			else
				middle.push_back(tmp);
		}
		else{
			string rev = tmp;
			reverse(rev.begin(), rev.end());
			it = find(arr.begin(), arr.end(), rev);

			if (it != arr.end()){
				arr.erase(it);
				subpal[tmp]++;
			}
			else
				arr.push_back(tmp);
		}
	}

	string aux;

	for (auto i: subpal){
		for (int j = 0; j < i.second; j++)
			ans += i.first;
	}

	aux = ans;

	reverse(aux.begin(), aux.end());

	if (middle.size() != 0)
		ans += middle[0];

	ans += aux;

	cout << ans.length() << endl;
	cout << ans << endl;

	return 0;
}