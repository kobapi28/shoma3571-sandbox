#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;

  string ans_str = "";

  while (n!=0) {
    if (n%2==0) {
      n /= 2;
      ans_str = 'B' + ans_str;
    } else {
      n -= 1;
      ans_str = 'A' + ans_str;
    }
  }


  cout << ans_str << endl;
}