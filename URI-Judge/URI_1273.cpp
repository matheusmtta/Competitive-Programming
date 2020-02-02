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
	int n, flag = 0;
	while (1){
		cin >> n; if (n == 0) return 0;
    	if (flag) cout << endl; 
		
    	flag = 1;

		map <int, string> str;
		int mx = -1;

		string tmp;

		for (int i = 0; i < n; i++){
			cin >> tmp;
			str.insert({i, tmp});
			int p = tmp.length();
			if (p > mx)
				mx = p;
		}

		map<int, string>::iterator itr; 
     
    	for (itr = str.begin(); itr != str.end(); ++itr) {
    		int x = itr->second.length();
    		int aux = abs(x - mx);
    		while (aux --) cout << " "; 
        	cout << itr->second << endl;
    	}
	}
    
    return 0;
}