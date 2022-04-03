#include<iostream>
using namespace std;

int main() {
  string s,t;
  cin >> s >> t;

  if (s==t) {
    cout << "Yes" << endl;
    return 0;
  }


  for (int i=0; i<s.size()-1; i++){
    // 間違えていた時
    if (s[i]!=t[i]){
      // 1つ後ろのものとswap
      char tmp = s[i];
      s[i] = s[i+1];
      s[i+1] = tmp;

      // 同じか確認
      if(s==t) {
        cout <<  "Yes" << endl;
      }else {
        cout << "No" << endl;
      }

      break;
    }
  }

  return 0;
}