#include<iostream>
using namespace std;

int main(){
  int x;
  cin >> x;

  // xが0ではなく、100で割って余りが存在しなければOK
  if (x%100 == 0 && x!=0) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
  return 0;
}