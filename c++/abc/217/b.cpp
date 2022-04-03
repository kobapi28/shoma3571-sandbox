#include <iostream>
#include <string>
using namespace std;

// int main() {
//   bool abc = false, agc = false, ahc = false, arc = false;

//   for(int i=0; i<3; i++) {
//     string str;
//     cin >> str;

//     if (str == "ABC") {
//       abc = true;
//     } else if (str == "AGC") {
//       agc = true;
//     } else if (str == "ARC") {
//       arc = true;
//     } else {
//       ahc = true;
//     }
//   }

//   if (!abc) {
//     cout << "ABC" << endl;
//   } else if (!agc) {
//     cout << "AGC" << endl;
//   } else if (!ahc) {
//     cout << "AHC" << endl;
//   } else {
//     cout << "ARC" << endl;
//   }

//   return 0;
// }

int main() {
  int count = 0;
  for (int i=0; i<3; i++) {
    string str;
    cin >> str;

    
    if (str == "ABC") {
      count += 1;
    } else if (str == "AGC") {
      count += 2;
    } else if (str == "ARC") {
      count += 3;
    } else {
      count += 4;
    }
  }

  if (count == 6) {
    cout << "AHC" << endl;
  } else if (count == 7) {
    cout << "ARC" << endl;
  } else if (count == 8) {
    cout << "AGC" << endl;
  } else {
    cout << "ABC" << endl;
  }
}