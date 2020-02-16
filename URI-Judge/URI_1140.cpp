#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string str;
  int booli=1;
  while(1){
    getline(cin, str);
    if (str == "*") break;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    char equal = str[0];
    for (int i = 0; i < str.length(); i++){
      if (str[i] == ' ' && str[i+1] != str[0]){
        booli = 0;
        break;
      }
      else{
        booli = 1;
      }
    }
    booli == 1 ? cout << "Y" << endl: cout << "N" << endl;
  }
  return 0;
}
