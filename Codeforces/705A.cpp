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
	int n;
	cin >> n;
	
	bool flag = true;

	while (n--){
		if (flag){ 
			cout << "I hate ";
			if (n) cout << "that ";
			flag = false;
		}
		else{ 
			cout << "I love ";
			if (n) cout << "that ";
			flag = true;
		}
		if (!n) cout << "it" << endl;
	}
}