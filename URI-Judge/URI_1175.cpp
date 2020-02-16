#include <iostream>

int main(){
  int n[20], aux;
  for (int i = 0; i < 20; i++){
    std::cin >> n[i];
  }
  for (int i = 0; i < 10; i++){
    aux = n[i];
    n[i] = n[(20-i)-1];
    n[(20-i)-1] = aux;
  }
  for (int i = 0; i < 20; i++){
    std::cout << "N[" << i << "] = " << n[i] << std::endl;
  }
}
