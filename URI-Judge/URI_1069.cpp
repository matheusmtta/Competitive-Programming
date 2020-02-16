#include <bits/stdc++.h>

using namespace std;

int idx=0;
int d=0;

int ShineBrightLikeADiamond(string str, int idx){
  if (idx == str.length()) return 0;
  if (str[idx]=='.') {
    idx+=1;
    return 0 + ShineBrightLikeADiamond(str, idx);
  }
  else if (str[idx] == '<'){
    idx+=1;
    d+=1;
    return 0 + ShineBrightLikeADiamond(str, idx);
  }
  else if (str[idx] == '>'){
    if (d>0) {
      idx+=1;
      d-=1;
      return 1 + ShineBrightLikeADiamond(str, idx);
    }
    else {
      idx+=1;
      return 0 + ShineBrightLikeADiamond(str, idx);
    }
  }
}

int main(){
  int n =0, resp=0;
  string str;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> str;
    resp = ShineBrightLikeADiamond(str, idx);
    cout << resp << endl;
    idx = d = 0;
  }
}
