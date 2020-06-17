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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		 int n; cin >> n;
		 map <int, pair<int, int>> mp;
        
         for (int i = 0; i < n; i++){
             int d, k; cin >> d >> k;
             mp[i+1] = {d, k};
         }
        
        
         bitset <1010> aux;
         vector <int> ans;

         while (true){
         	if (aux.count() == n) break;
         	pair <int, pair<int, int>> tmp;
            bool flag = false;
         	for (int j = 1; j <= n; j++){
         		if (!aux[j]){
         			int a = tmp.second.first*mp[j].second;
         			int b = tmp.second.second*mp[j].first;
         			if (b < a || !flag){
                        tmp.first = j;
         				tmp.second = mp[j];
                        flag = true;
         			}
         		}
         	}
            aux[tmp.first] = 1;
            ans.push_back(tmp.first);
         }
         for (int i = 0; i < n; i++){
         	cout << ans[i];
         	if (i < n-1) cout << " ";
         }
         cout << endl;
         if (t) cout << endl;
	}

	return 0;
}