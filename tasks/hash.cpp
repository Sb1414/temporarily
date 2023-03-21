#include <iostream>
#include <cstring>
#define SIZE 10

using namespace std;

// Структура для хранения ключа и указателей на начало и конец списка
struct List {
    char key[50];
    int num;
    List *next, *prev;
};

// Класс хэш-таблицы
class HashTable {
public:
    HashTable(); // Конструктор
    void add(char key[], int n); // Добавление ключа в таблицу
    bool search(char key[]); // Поиск ключа в таблице
    void remove(char key[]); // Удаление ключа из таблицы
    void print(); // Вывод таблицы на экран
private:
    List *arr[SIZE]; // Массив списков
    unsigned int hash(char key[]); // Хэш-функция
};

// Конструктор
HashTable::HashTable() {
    // Инициализация элементов массива
    for(int i = 0; i < SIZE; i++) {
        arr[i] = nullptr;
    }
}

// Хэш-функция
unsigned int HashTable::hash(char key[]) {
    unsigned int hash = 0;
    for(size_t i = 0; i < strlen(key); i++) {
        hash += key[i];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash % SIZE;
}

// Добавление ключа в таблицу
void HashTable::add(char key[], int n) {
    unsigned int index = hash(key);
    List *new_list = new List;
    strcpy(new_list->key, key); // Копируем ключ в создаваемую структуру
    new_list->num = n;
    new_list->next = new_list->prev = nullptr;
    if(arr[index] == nullptr) {
        arr[index] = new_list;
    } else {
        List *tmp = arr[index];
        while(tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new_list;
        new_list->prev = tmp;
    }
}

// Поиск ключа в таблице
bool HashTable::search(char key[]) {
    unsigned int index = hash(key);
    List *tmp = arr[index];
    while(tmp != nullptr) {
        if(strcmp(tmp->key, key) == 0) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

// Удаление ключа из таблицы
void HashTable::remove(char key[]) {
    unsigned int index = hash(key);
    List *tmp = arr[index];
    if(tmp == nullptr) {
        return;
    }
    if(strcmp(tmp->key, key) == 0) {
        arr[index] = tmp->next;
        if(tmp->next != nullptr) {
            tmp->next->prev = nullptr;
        }
        delete tmp;
        return;
    }
    while(tmp != nullptr && strcmp(tmp->key, key) != 0) {
        tmp = tmp->next;
    }
    if(tmp == nullptr) {
        return;
    }
    tmp->prev->next = tmp->next;
    if(tmp->next != nullptr) {
        tmp->next->prev = tmp->prev;
    }
    delete tmp;
}

// Вывод таблицы на экран
void HashTable::print() {
    for(int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        List *tmp = arr[i];
        while(tmp != nullptr) {
            cout << tmp->key << " {" << tmp->num << "} ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

int main() {
    HashTable table; // Создаем объект хэш-таблицы
    char str[20]; // массив символов для хранения строки
    strcpy(str, "Kalkamanova");
    table.add(str, 1);
    strcpy(str, "world");
    table.add(str, 2);
    strcpy(str, "hash");
    table.add(str, 3);
    strcpy(str, "table");
    table.add(str, 4);
    strcpy(str, "example");
    table.add(str, 5);
    strcpy(str, "chain");
    table.add(str, 6);
    strcpy(str, "search");
    table.add(str, 7);
    strcpy(str, "remove");
    table.add(str, 8);
    strcpy(str, "Lushenko");
    table.add(str, 9);
    strcpy(str, "Onejko");
    table.add(str, 10);
    strcpy(str, "Vinogradova");
    table.add(str, 11);
    strcpy(str, "Lavrova");
    table.add(str, 12);
    strcpy(str, "Allova");
    table.add(str, 13);
    strcpy(str, "Simakova");
    table.add(str, 14);
    table.print();

    // cout << "search(hello): " << table.search("hello") << endl;
    // cout << "search(foo): " << table.search("foo") << endl;

    // table.remove("hello");
    // table.remove("world");
    // table.remove("example");
    // table.print();

    return 0;
}