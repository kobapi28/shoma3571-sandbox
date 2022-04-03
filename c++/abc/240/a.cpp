#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int a,b;
  cin >> a >> b;
  if (abs(b-a)==1 || (a==1 && b==10)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}