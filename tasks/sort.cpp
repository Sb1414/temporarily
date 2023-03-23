#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int insertionSort(vector<int>& arr) {
  int n = arr.size();
  int comparisons = 0;
  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
      comparisons++;
    }
    arr[j + 1] = key;
  }
  return comparisons;
}

int bubbleSort(vector<int>& arr) {
  int n = arr.size();
  int comparisons = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
      comparisons++;
    }
  }
  return comparisons;
}

void fillNums(int n) {
  const string filename = "numbers.txt";
  ofstream file(filename);  // создаем файл для записи чисел
  if (file.is_open()) {
    for (int i = 0; i < n; ++i) {
      file << rand() % 1000 << " ";
    }
    file.close();
  } else {
    cout << "Файл не был сохранен\n" << endl;
  }
  cout << "\nЧисла сгенерированы и сохранены в файл (для одинакового анализа "
          "обоих способов сортировки): "
       << filename << endl;
}

void fillArray(vector<int>& arr) {
  arr.clear();
  ifstream fin("numbers.txt");
  int num;
  while (fin >> num) {
    arr.push_back(num);
  }
  fin.close();
}

void printArray(const vector<int>& arr) {
  const int n = arr.size();
  if (arr[0] == 0 && arr[n - 1] == 0) {
    cout << "\nМассив пуст\n";
  } else {
    for (int i = 0; i < n; i++) {
      cout << " " << arr[i];
    }
  }
}

void useMethodInsertion(vector<int>& arr) {
  cout << endl << "================ BEFORE ==============" << endl;
  printArray(arr);

  auto start = chrono::high_resolution_clock::now();
  cout << "\nКоличество сравнений: " << insertionSort(arr) << endl;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed_time = end - start;
  cout << endl << "================ AFTER ==============" << endl;
  printArray(arr);

  cout << "\nЗатраченное время: " << elapsed_time.count() << " секунд" << endl;
}

void useMethodBubble(vector<int>& arr) {
  cout << endl << "================ BEFORE ==============" << endl;
  printArray(arr);

  auto start = chrono::high_resolution_clock::now();
  cout << "\nКоличество сравнений: " << bubbleSort(arr) << endl;
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed_time = end - start;
  cout << endl << "================ AFTER ==============" << endl;
  printArray(arr);

  cout << "\nЗатраченное время: " << elapsed_time.count() << " секунд" << endl;
}

void draw() {
  cout << "\n===============================================================\n";
}

void menu() {
  cout << "\n1. Вывод текущего состояния массива\n"
       << "2. Использовать метод сортировки вставками\n"
       << "3. Использовать метод сортировки пузырьком\n"
       << "4. Заново заполнить массив рандомными числами\n"
       << "~~ Для выхода нажмите любую клавишу ~~\n";
}

int main() {
  const int n = 10000;
  vector<int> arr(n);
  fillNums(n);
  bool fl = true, checkState = true;
  while (fl) {
    menu();
    int num;
    cin >> num;
    switch (num) {
      case 1:
        draw();
        if (checkState) {
          fillArray(arr);
          checkState = false;
        }
        printArray(arr);
        draw();
        break;
      case 2:
        draw();
        fillArray(arr);
        useMethodInsertion(arr);
        draw();
        break;
      case 3:
        draw();
        fillArray(arr);
        useMethodBubble(arr);
        draw();
        break;
      case 4:
        draw();
        fillArray(arr);
        draw();
        break;
      default:
        fl = false;
        break;
    }
  }
}
