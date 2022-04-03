#include<iostream>
#include<math.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;

  // 前にintをつけてあげることで通った
  cout << (int)pow(32, a-b) << endl;
  return 0;
}