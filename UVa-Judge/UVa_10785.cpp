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

string vowels = "AAAAAAAAAAAAAAAAAAAAAUUUUUUUUUUUUUUUUUUUUUEEEEEEEEEEEEEEEEEEEEEOOOOOOOOOOOOOOOOOOOOOIIIIIIIIIIIIIIIIIIIII";
string conson = "JJJJJSSSSSBBBBBKKKKKTTTTTCCCCCLLLLLDDDDDMMMMMVVVVVNNNNNWWWWWFFFFFXXXXXGGGGGPPPPPYYYYYHHHHHQQQQQZZZZZRRRRR";

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, q = 1;
	cin >> t;

	while (q <= t){
		int n; cin >> n;
		int a = 0, b = 0;
		if (n%2 == 1){
			a = 1 + n/2;
		}
		else a = n/2;
		b = n/2;

		string str1 = vowels.substr(0, a);
		string str2 = conson.substr(0, b);

		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());

		cout << "Case " << q << ": ";
		for (int i = 0; i < str2.size(); i++)
			cout << str1[i] << str2[i];
		if (n%2 == 1) cout << str1[b];
		cout << endl;
		q++;
	}

	return 0;
}