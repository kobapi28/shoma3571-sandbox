#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  stack<int> st;
  st.push(a[0]);
  // 最初のカウントは必ず1
  cout << 1 << endl;

  for (int i=1; i<n; i++) {
    // 0個のときはpushだけ
    if (st.size() == 0) {
      st.push(a[i]);
      cout << 1 << endl;
      continue;
    }

    if (st.top() == a[i]) {
      st.push(a[i]);
      if (i+1 == n) {
        // 最後なら削除の処理
        int eraseNum = a[i];
        while (st.size() > 0 && st.top() == eraseNum) {
          st.pop();
        }
      }
    } else {
      // topと違ったら、前までのものがtopと同じじゃなかったかを確認
      int no1 = st.top();
      st.pop();
      if (st.size() != 0) {
        int no2 = st.top();
        if (no1 == no2) {
          st.push(no1);
          while (st.size() > 0 && st.top() == no2) {
            st.pop();
          }
        }
      } else {
        st.push(no1);
      }
      
      // 前までのものを消した後にpush
      st.push(a[i]);
    }

    cout << st.size() << endl;
  }
  return 0;
}