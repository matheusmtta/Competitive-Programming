/*
* TDA Racional
* URI Online Judge 1022
* 06/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int x1, x2, y1, y2;
  char fill1, fill2, op;
  while(n--){
    cin >> x1 >> fill1 >> x2 >> op >> y1 >> fill2 >> y2;
    //cout << op;
    if (op == '-' || op == '+'){
      int num;
      int dem = x2*y2;
      if (op == '+') {num = ((dem/x2)*x1)+((dem/y2)*y1);}
      if (op == '-') {num = ((dem/x2)*x1)-((dem/y2)*y1);}
      int s_dem = dem, s_num = num;
      int i = 2;
      //if (s_num%2==0 && s_dem%2==0){s_num/=2; s_dem/=2;}
      while (i <= abs(s_dem) || i <= abs(s_num)){
        if (s_num%i==0 && s_dem%i==0) {s_num/=i; s_dem/=i; continue;}
        i++;
      }
      printf("%d/%d = %d/%d\n", num, dem, s_num, s_dem);
    }
    else if (op == '/'){
      int dem = x2*y1;
      int num = x1*y2;
      int s_dem = dem, s_num = num;
      int i = 2;
      //if (s_num%2==0 && s_dem%2==0){s_num/=2; s_dem/=2;}
      while (i <= abs(s_dem) || i <= abs(s_num)){
        if (s_num%i==0 && s_dem%i==0) {s_num/=i; s_dem/=i; continue;}
        i++;
      }
      printf("%d/%d = %d/%d\n", num, dem, s_num, s_dem);
    }
    else if (op == '*'){
      int num = y1*x1;
      int dem = x2*y2;
      int s_dem = dem, s_num = num;
      int i = 2;
      //if (s_num%2==0 && s_dem%2==0){s_num/=2; s_dem/=2;}
      while (i <= abs(s_dem) || i <= abs(s_num)){
        if (s_num%i==0 && s_dem%i==0) {s_num/=i; s_dem/=i; continue;}
        i++;
      }
      printf("%d/%d = %d/%d\n", num, dem, s_num, s_dem);
    }
  }
}
