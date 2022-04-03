#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;

  int a = 0;
  long long x = 1;

  while (n >= x) {
    x *= 2;
    a++; 
  }

  cout << a-1 << endl;
}