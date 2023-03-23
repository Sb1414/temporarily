#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

pair<int, int> quick_sort(vector<int>& arr, int left, int right) {
  int compare = 0;
  int swap = 0;
  int i = left, j = right;
  int pivot = arr[(left + right) / 2];
  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
      compare++;
    }
    while (arr[j] > pivot) {
      j--;
      compare++;
    }
    if (i <= j) {
      swap++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }
  if (left < j) {
    pair<int, int> res = quick_sort(arr, left, j);
    compare += res.first;
    swap += res.second;
  }
  if (i < right) {
    pair<int, int> res = quick_sort(arr, i, right);
    compare += res.first;
    swap += res.second;
  }
  return make_pair(compare, swap);
}

void fillArray(vector<int>& arr, int n) {
  arr.clear();
  for (int i = 0; i < n; ++i) {
    arr.push_back(rand() % 1000);
  }
}

void printArray(const vector<int>& arr) {
  int size = arr.size();
  for (int i = 0; i < size; i++) {
    cout << " " << arr[i];
  }
}

int main() {
  const int n = 10000;
  vector<int> arr(n);
  fillArray(arr, n);
  cout << "Элементов в массиве " << n << endl;
  cout << "\nДо сортировки:\n";
  printArray(arr);
  auto start = chrono::high_resolution_clock::now();
  pair<int, int> res = quick_sort(arr, 0, arr.size() - 1);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed_time = end - start;
  cout << "\nПосле сортировки:\n";
  printArray(arr);
  cout << endl << "Количество сравнений: " << res.first << endl;
  cout << "Количество пересылок: " << res.second << endl;
  cout << "Затраченное время: " << elapsed_time.count() << " секунд" << endl;
  return 0;
}

  