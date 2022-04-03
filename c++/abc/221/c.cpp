#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  sort(s.begin(), s.end());

  int max = 0;
  
  do {
    for(int i=1; i<s.size(); i++){
      string first_str = s.substr(0,i);
      string second_str = s.substr(i ,s.size()-1);

      if (first_str[0]!='0' && second_str[0]!='0'){
        int first = stoi(first_str);
        int second = stoi(second_str);

        max = max < (first * second) ? first * second : max;
      }
    }
  } while(next_permutation(s.begin(), s.end()));

  cout << max << endl;
}