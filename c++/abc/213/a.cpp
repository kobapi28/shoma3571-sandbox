#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string ConvertToBinary(int x) {
  string ans = "";
  for(int i=7; i>=0; i--) {
    int z = x / (int)pow(2, i);
    if (z == 1) {
      x -= (int)pow(2,i);
      ans += '1';
    } else {
      ans += '0';
    }
  }

  return ans;
}

int ConvertToDecimal(string s) {
  int ans = 0;
  for (int i=0; i<8; i++) {
    if (s[i] == '1') {
      ans += (int)pow(2, 8-i-1);
    }
  }

  return ans;
}

int main() {
  int a,b;
  cin >> a >> b;

  string binaryA = ConvertToBinary(a);
  string binaryB = ConvertToBinary(b);

  string ans = "";

  for (int i=7; i>=0; i--) {
    if (binaryA[i] != binaryB[i]){
      ans = '1' + ans;
    } else {
      ans = '0' + ans;
    }
  }

  cout << ConvertToDecimal(ans) << endl;
}