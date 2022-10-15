#include <iostream>
int main();
int main() {
    double x{};
    std::cout << "Enter value of x: ";
    std::cin >> x;
      
    // This local variable should hold the result of stair( x )
      int stair {};
  
      for (int i = 0 ; i <=x; i++) {
        if ((i > x-1) && (i <= x) && (x>=0)){ 
          stair = i;
        }
      }
      for (int i = 0 ; i > x; i--) {
        if ((i >= x) && (i <= x+1.) && (x < 0)){        
          stair = i-1;
      }
    }
   // TASK: write code that calculates an integer value
    // corresponding to the value of the function stair( x ) here

    std::cout << "The value of stair(x) is: ";
    std::cout << stair << std::endl;
    return 0;
}