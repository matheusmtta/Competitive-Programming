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

	int n; cin >> n;
	string str; cin >> str;

	string tmp;

	char c = 'z';

	while (c > 'a'){
		string tmp;

		bool change = false;

		vector <int> aux((int)str.length(), 0);
		for (int i = 0; i < str.length(); i++){
			if (str[i] == c){
				if (i != 0 && str[i-1] == c-1) aux[i] = 1;
				if (i != str.length()-1 && str[i+1] == c-1) aux[i] = 1;
			}
		}

		for (int i = 0; i < str.length(); i++){
			if (!aux[i]) tmp += str[i];
			else change = true;
		}

		if (!change) c--;

		str = tmp;
	}

	cout << n - str.length() << endl;	

	return 0;
}