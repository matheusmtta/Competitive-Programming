#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  while (cin >> n >> m){
    map <char, char> cifra;
    string g, s, str;
    cin.ignore();
    getline(cin, g);
    getline(cin, s);
    for (int i = 0; i < n; i++){
      cifra.insert({s[i], g[i]});
      cifra.insert({g[i], s[i]});
    }
    for (int i = 0; i < m; i++){
      getline(cin, str);
      string resp;
      for (int j=0; j < str.length(); j++){
        char aux = toupper(str[j]);
        if (cifra.count(aux)){
           if (isupper(str[j])) {
             char aux2 = cifra[aux];
             resp+=aux2;
           }
           else{
              char aux3 = cifra[aux];
              resp+=(char)tolower(aux3);
            }
        }
       else resp+= str[j];
      }
      cout << resp << endl;
      resp.erase();
    }
    cout << endl;
  }
  return 0;
}
