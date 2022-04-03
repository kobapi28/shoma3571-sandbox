#include <iostream>
using namespace std;

int main() {
  long long x;
  cin >> x;

  if (x < 0) {
    if (x%10 != 0) {
      x -= 10;
    }
    cout << x/10 << endl;
  } else {
    cout << x/10 <<endl;
  }
}