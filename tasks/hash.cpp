#include <cstring>
#include <iostream>
#define M 10

using namespace std;

struct List {
  char key[50];
  int num;
  List *next, *prev;
};

class HashTable {
 public:
  HashTable();
  void add(char key[], int n);
  void searchAndCount(char key[]);
  void remove(char key[]);
  void print();
  int getTotalComparisons();
  bool tableIsEmpty();

 private:
  int total_comparisons;
  List *arr[M];
  unsigned int hash(char key[]);
};

HashTable::HashTable() {
  for (int i = 0; i < M; i++) {
    arr[i] = nullptr;
  }
}

unsigned int HashTable::hash(char key[]) {
  unsigned int hash = 0;
  for (size_t i = 0; i < strlen(key); i++) {
    hash += key[i];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  return hash % M;
}

void HashTable::add(char key[], int n) {
  total_comparisons = 0;
  unsigned int index = hash(key);
  int comparisons = 0;
  List *new_list = new List;
  strcpy(new_list->key, key);
  new_list->num = n;
  new_list->next = new_list->prev = nullptr;
  if (arr[index] == nullptr) {
    arr[index] = new_list;
  } else {
    List *tmp = arr[index];
    while (tmp->next != nullptr) {
      tmp = tmp->next;
      comparisons++;
    }
    comparisons++;
    tmp->next = new_list;
    new_list->prev = tmp;
  }
  total_comparisons += comparisons;
}

int HashTable::getTotalComparisons() { return total_comparisons; }

void HashTable::searchAndCount(char key[]) {
  total_comparisons = 0;
  unsigned int index = hash(key);
  List *tmp = arr[index];
  while (tmp != nullptr) {
    total_comparisons++;
    if (strcmp(tmp->key, key) == 0) {
      cout << "Найден ключ " << tmp->key << " с значением " << tmp->num << endl;
      cout << "Количество сравнений: " << total_comparisons << endl;
      return;
    }
    tmp = tmp->next;
  }
  cout << "Ключ " << key << " не найден" << endl;
  cout << "Количество сравнений: " << total_comparisons << endl;
}

void HashTable::remove(char key[]) {
  unsigned int index = hash(key);
  List *tmp = arr[index];
  while (tmp != nullptr && strcmp(tmp->key, key) != 0) {
    tmp = tmp->next;
  }
  if (tmp == nullptr) {
    cout << "Ключ " << key << " не найден" << endl;
    return;
  }
  if (tmp->prev != nullptr) {
    tmp->prev->next = tmp->next;
  } else {
    arr[index] = tmp->next;
  }
  if (tmp->next != nullptr) {
    tmp->next->prev = tmp->prev;
  }
  delete tmp;
  cout << "Ключ " << key << " удален" << endl;
}

void HashTable::print() {
  for (int i = 0; i < M; i++) {
    cout << i << ": ";
    List *tmp = arr[i];
    while (tmp != nullptr) {
      cout << tmp->key << " {" << tmp->num << "} ";
      tmp = tmp->next;
    }
    cout << endl;
  }
}

void draw() {
  cout << "\n===============================================================\n";
}

void addKeys(HashTable &table) {
  int num;
  cout << "\nСколько ключей внести? ";
  cin >> num;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Not num" << std::endl;
  } else {
    char str[20];
    for (int i = 1; i <= num; i++) {
      cout << "\nВведите ключ " << i << ": ";
      cin >> str;
      table.add(str, i);
      cout << "\nсравнений: " << table.getTotalComparisons();
    }
  }
}

void search(HashTable &table) {
  char str[20];
  cout << "Введите слово, которое нужно найти: ";
  cin >> str;
  table.searchAndCount(str);
}

void deleteKey(HashTable &table) {
  char str[20];
  cout << "Введите слово, которое нужно удалить: ";
  cin >> str;
  table.remove(str);
}

void addReadyMadeKeys(HashTable &table) {
  char str[20];
  strcpy(str, "Kalkamanova");
  table.add(str, 1);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Stroyev");
  table.add(str, 2);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Podyomny");
  table.add(str, 3);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Hasymov");
  table.add(str, 4);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Tatishev");
  table.add(str, 5);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Chistovich");
  table.add(str, 6);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Djumayev");
  table.add(str, 7);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Kuznetsov");
  table.add(str, 8);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Lushenko");
  table.add(str, 9);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Onejko");
  table.add(str, 10);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Vinogradova");
  table.add(str, 11);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Lavrova");
  table.add(str, 12);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Allova");
  table.add(str, 13);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Simakova");
  table.add(str, 14);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Lapshin");
  table.add(str, 15);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Bushuyeva");
  table.add(str, 16);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Ilyina");
  table.add(str, 17);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Vorobyov");
  table.add(str, 18);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Vasilyev");
  table.add(str, 19);
  cout << "\nсравнений: " << table.getTotalComparisons();
  strcpy(str, "Tyurina");
  table.add(str, 20);
  cout << "\nсравнений: " << table.getTotalComparisons();
  cout << endl;
  table.print();
}

void menu() {
  cout << "\n1. Вывод текущего состояния таблицы\n"
       << "2. Внести 20 заранее заготовленных ключей (возможно только 1 раз)\n"
       << "3. Добавление нового ключа в таблицу с подсчетом сделанных при этом "
          "сравнений\n"
       << "4. Поиск заданного ключа в таблице с подсчетом сделанных при этом "
          "сравнений\n"
       << "5. Удаление заданного ключа из таблицы\n"
       << "~~ Для выхода нажмите любую клавишу ~~\n";
}

int main() {
  // setlocale(LC_ALL, "rus");
  HashTable table;
  bool fl = true, checkTwo = true;
  while (fl) {
    menu();
    int num;
    cin >> num;
    switch (num) {
      case 1:
        draw();
        table.print();
        draw();
        break;
      case 2:
        draw();
        if (checkTwo) {
          addReadyMadeKeys(table);
          checkTwo = false;
        } else {
          cout << "\nЭто действие нельзя выполнить повторно!\n";
        }
        draw();
        break;
      case 3:
        draw();
        addKeys(table);
        draw();
        break;
      case 4:
        draw();
        search(table);
        draw();
        break;
      case 5:
        draw();
        deleteKey(table);
        draw();
        break;
      default:
        fl = false;
        break;
    }
  }
  return 0;
}