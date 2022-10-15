#include <iostream>

int main();
int main() {

  double n{};
  double y{};
  double z{};
  double a{};
  double x{};
  std::cout << "Enter the currency in CAD: "<< std::endl;
  std::cin >> n;

  
  
  x = n/1.30;
  y = x * 0.86;
  z = 0.87 * y;
  a = 100 * x;

std::cout << "There are " << x << " USD"<< std::endl;
std::cout << "There are " << y << " Pound Sterling"<< std::endl;
std::cout << "There are " << z << " Euro"<< std::endl;
std::cout << "There are " << a << " US Penny"<< std::endl;

  return 0;
}