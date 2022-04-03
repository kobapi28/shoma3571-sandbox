#include<iostream>
using namespace std;

int main() {
  int x,y;
  char dot;
  cin >> x >> dot >> y;

  if (y <= 2) {
    cout << x << '-' << endl;
  } else if (y <= 6) {
    cout << x << endl;
  } else {
    cout << x << '+' << endl;
  }

  return 0;
}