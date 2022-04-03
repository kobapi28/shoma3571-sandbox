#include <iostream>
#include <math.h>
using namespace std;

long BaseTen(int k, string value) {
  long ans = 0;
  for(int i=0; i<value.size(); i++){
    ans += int(value[i] - '0') * (int)pow(k, value.size()-1-i);
  }
  return ans;
}

int main(){
  int k;
  string a,b;
  cin >> k >> a >> b;

  cout << BaseTen(k, a) * BaseTen(k, b) << endl;
}