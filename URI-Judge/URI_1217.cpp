#include <iostream>
#include <string>
#include <iomanip>

int main(){

      int n=0;
      int day=1, sizeS;

      std::cin >> n;

      float finalValue=0;
      float finalWeight=0;

      while (day <= n){

        float value=0;
        int nfruits=1, amount=0, i=0;

        std::cin >> value;

        finalValue += value;

        std::string fruits;
        std::cin.ignore();
        std::getline(std::cin, fruits);

        sizeS = fruits.size();

        for (i = 0; i < sizeS; i++) {
              if (fruits[i] == ' ') {
                    nfruits++;
              }
        }

        finalWeight += nfruits;

        std::cout << "day " << day << ": " << nfruits << " kg" << std::endl;

        day++;
      }

      float meanValue=0, meanAmount=0;

      meanValue = finalValue/n;
      meanAmount = finalWeight/n;

      std::cout << std::fixed << std::setprecision(2) << meanAmount << " kg by day"  << std::endl;
      std::cout <<  "R$ " << std::fixed << std::setprecision(2) << meanValue << " by day" << std::endl;
}
