#include <iostream>
using namespace std;

int main() {
  long long x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;

  long long absx = abs(x2-x1);
  long long absy = abs(y2-y1);

  if (abs(absx) > 4 || abs(absy) > 4) {
    cout << "No" << endl;
    return 0;
  }

  if (x1 == x2 && (absy == 2 || absy == 4)) {
    cout << "Yes" << endl;
  } else if (y1 == y2 && (absx == 2 || absx == 4)) {
    cout << "Yes" << endl;
  } else if (absx == 1 && (absy == 1 || absy == 3)) {
    cout << "Yes" << endl;
  } else if (absy == 1 && (absx == 1 || absx == 3)) {
    cout << "Yes" << endl;
  } else if (absx == 3 && absy == 3) {
    cout << "Yes" << endl;
  } else if ((absx == 2 && absy == 4) || (absx == 4 && absy == 2)){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


}