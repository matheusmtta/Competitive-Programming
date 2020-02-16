#include <bits/stdc++.h>

using namespace std;

int n, m, k, ans=0;

int main(){
  string str;
  int aux = n;
  cin >> n;
  getchar();
  getchar();
  while(n--){
    k=0;
    map <string, double> trees;
    map <string, double>::iterator i;
    while(getline(cin, str)){
      if (str.size() == 0)
        break;
      trees[str]++;
      k++;
    }
    for (i = trees.begin(); i != trees.end(); i++){
      cout << i->first << " ";
      printf("%.4lf\n", (i->second/k)*100);
    }
    if (n != 0) cout << endl;
  }
  return 0;
}