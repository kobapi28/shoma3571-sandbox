#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
  for (int i=0; i<size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void quickSort(int arr[], int left, int right) {
  // pivot: 基準となる値
  int pivot, i, j;

  // 並び替える必要がない場合
  if (left >= right) return;

  pivot = arr[left];
  i = left;
  j = right;


  while(true) {
    // pivotより大きいものが見つかれば、後ろに持っていく必要があるのでwhileを抜ける
    while (arr[i] < pivot) i++;
    // pivotより小さいものが見つかれば、前に持っていく必要があるのでwhileを抜ける。
    while (pivot < arr[j]) j--;

    // 見つかった値の順序が逆になったら終了
    if (i >= j) break;

    // 値を交換
    swap(&arr[i], &arr[j]);
    // 値を交換したので、その次からまた再開する
    i++; j--;
  }

  // 左のデータを対象にして、クイックソート
  if (left < i - 1) quickSort(arr, left, i-1);
  // 右のデータを対象にして、クイックソート
  if (j + 1 < right) quickSort(arr, j+1, right);

  printArray(arr, right+1);
}

int main() {
  int size;
  cin >> size;

  int arr[size];
  for (int i=0; i<size; i++) {
    cin >> arr[i];
  }

  printArray(arr, size);
  quickSort(arr, 0, size-1);
}