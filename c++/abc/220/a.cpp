#include <iostream>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;

  for(int i=1;;i++){
    if(i*c >= a && i*c <= b) {
      cout << i*c << endl;
      break;
    }

    if(i*c > b) {
      cout << -1 << endl;
      break;
    }
  }

  return 0;
}