 #include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void recover_posfix(string tree1, string tree2){
	char root = tree1[0];
	int p = tree2.find(root);

	if (p != 0){
		recover_posfix(tree1.substr(1, p), tree2.substr(0, p));
	}
	if (p+1 < tree1.size()){
		recover_posfix(tree1.substr(p+1), tree2.substr(p+1));
	}

	cout << root;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string prefix, infix;

	while (cin >> prefix >> infix){
		recover_posfix(prefix, infix);
		cout << endl;
	}
	
	return 0;
}