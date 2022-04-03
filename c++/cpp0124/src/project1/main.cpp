#include<iostream>
#include "func.h"

int main(){
  for (double x=-1.0; x<1; x+=0.1){
    std::cout << std::scientific;
    std::cout << x << ",";
    std::cout << func(x) << ",";
    std::cout << dfunc(x) << std::endl;
    // 課題3
    std::cout << name() << ",";
  }
  return 0;
}