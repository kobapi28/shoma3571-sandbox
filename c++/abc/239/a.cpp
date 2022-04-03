#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
  long long  h;
  cin >> h;
  cout << setprecision(10) << sqrtl(h*(12800000 + h)) << endl;
  return 0;
}