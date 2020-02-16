#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int n, m, sum=0;
  string str;
  while (1){
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < n; i++){
      cin >> m;
      cin.ignore();
      getline(cin, str);
      if (str == "suco de laranja") sum = sum+(120*m);
      else if (str == "morango fresco") sum = sum + (85*m);
      else if (str == "mamao") sum = sum + (85*m);
      else if (str == "goiaba vermelha") sum = sum + (70*m);
      else if (str == "manga") sum = sum + (56*m);
      else if (str == "laranja") sum = sum + (50*m);
      else if (str == "brocolis") sum = sum + (34*m);
    }
    if (sum >= 110 && sum <= 130) cout << sum << " mg" << endl;
    else if (sum < 110) cout << "Mais " << 110-sum << " mg" << endl;
    else if (sum > 130) cout << "Menos " << sum-130 << " mg" << endl;
    sum = 0;
  }
  return 0;
}
