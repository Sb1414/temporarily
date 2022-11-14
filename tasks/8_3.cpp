#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> class Queue
{
    private:
        int newSize; // размер заполенной очереди
        vector<int> arr;
        vector<int> dell;

    public:

        void size() {
            if (arr.empty()) {
                cout << "\nстек пуст\n";
            } else {
                T count = arr.size();
                cout << "\n Количество элементов в стеке = " << count << endl;
            }
        }

        void push(int num) {
            bool f = true, fdel = true;
            int n, a, n1, delOrNot;
            int size0 = newSize;
            if (size0  >= num) {
                cout << "Заполнение стека невозможно, иначе он будет переполнен!\n";
            } else {
                while (fdel) {
                    cout << "как заполнить?\n1. Новыми данными\n2. Из стека удаленных\n";
                    cin >> delOrNot;
                    if (delOrNot == 1) {
                        cout << "\nВведите сколько элементов внести в стек: ";
                        while (f) {
                            cin >> n;
                            if (n <= num - size0) {
                                cout << "Как заполнить стек?\n" << "1. Вручную\n" << "2. Рандомом\n" << "3. не заполнять\n";
                                cin >> n1;
                                if (n1 == 1) {
                                    for (int i = 0; i < n; i++) {
                                        cin >> a;
                                        arr.push_back(a);
                                    }
                                } else if (n1 == 2) {
                                    for (int i = 0; i < n; i++) {
                                        a = 1 + rand() % 10;
                                        arr.push_back(a);
                                    }
                                }
                                newSize += n;
                                f = false;
                            } else if (n == 0) {
                                f = false;
                            } else {
                                cout << "введите число меньше, вы выходите за границы стека!\nДля отмены введите 0\n";
                            }
                        }
                        fdel = false;
                    } else if (delOrNot == 2) {
                        if (dell.size() > 0) {
                            cout << "\nВведите сколько элементов внести в стек: \n ~~ Для отмены введите 0 ~~ \n";
                            while (f) {
                                cin >> n;
                                if (n <= (int)dell.size()) {
                                    for (int i = 0; i < n; i++) {
                                        int tmp = dell.back();
                                        arr.push_back(tmp);
                                        dell.erase(dell.begin()+n-i);
                                    }
                                    f = false;
                                } else if (n == 0) {
                                    f = false;
                                } else {
                                    cout << "введите число меньше, вы выходите за границы стека!\nДля отмены введите 0\n";
                                }
                            }
                            fdel = false;
                        } else {
                            cout << "Стек удаленных пуст, заполнение данным способом невозможно!\n";
                        }
                    }
                }
                
            }
        }

        // arr.insert(arr.begin() + i + newSize, a);

        void pop(int num) {
            int isc, n;
            cout << "как удалить?\n1. По индексу\n2. Заданный элемент\n3. Отмена, не удалять\n";
            cin >> isc;
            if (isc == 1) {
                cout << "Введите № элемента (отсчет с 1): ";
                cin >> n;
                if (n > 0 && n <= num) {
                    arr.erase(arr.begin() + n-1);
                } else {
                    cout << "число выходит за пределы\n";
                }
            } else if (isc == 2) {
                int c = 0;
                cout << "Введите элемент: ";
                cin >> n;
                try {
                    for (int i = 0; i < num; i++) {
                        if (arr[i] == n) c++;
                    }
                    if (c > 1) {
                        cout << "Таких элементов больше одного! Что делать?\n1. Удалить все повторения\n2. Удалить первое\n3. Удалить последнее\n";
                        int tmp;
                        cin >> tmp;
                        if (tmp == 1) {
                            for (int i = 0; i < num; i++)
                                if (arr[i] == n) arr.erase(arr.begin() + i);
                        } else if (tmp == 2) {
                            bool m = true;
                            for (int i = 0; m == true; i++) {
                                if (arr[i] == n) {
                                    arr.erase(arr.begin() + i);
                                    m = false;
                                }                                
                            }
                        } else if (tmp == 3) {
                            int c1 = 0;
                            for (int i = 0; c1 != c; i++) {
                                if (arr[i] == n) c1++;
                                if (c1 == c) arr.erase(arr.begin() + i);
                            }
                        } else {
                            cout << "ничего не выбрано!\n";
                        }
                    } else if (c == 1) {
                        for (int i = 0; i < num; i++) {
                            if (arr[i] == n) arr.erase(arr.begin() + i);
                        }
                    } else {
                        cout << "число не найдено!\n";
                    }
                } catch (int x)
                {
                    cout << "Некорректный ввод\n" << '\n';
                }
            }
        }

        void show() {
            for(auto e : arr) cout << setw(3) << e;
                cout << endl;
        }

        void search(int num) {
            int c = 0, n;
            cout << "Введите элемент: ";
            cin >> n;
            try {
                for (int i = 0; i < num; i++) {
                    if (arr[i] == n) {
                        c++;
                        cout << setw(3) << arr[i];
                    }
                }
                if (c > 0) cout << " <- элемент\n";
                for (int i = 0; i < num; i++) {
                    if (arr[i] == n) cout << setw(3) << i+1;
                }
                if (c > 0) cout << " <- индекс\n";
                if (c == 0) {
                    cout << "число не найдено\n";
                }
            } catch (int x)
            {
                cout << "Некорректный ввод" << '\n';
            }
        }

        void insert(int num) {
            bool f = true;
            int n, a, n1;
            int size0 = newSize;
            if (size0  >= num-1) {
                cout << "Заполнение стека невозможно, иначе он будет переполнен!\n";
            } else {
                cout << "\nВнести ПОСЛЕ (введите 1) или ДО (введите 2) заданного элемента?: ";
                while (f) {
                    cin >> n;
                    if (n <= num - size0) {
                        if (n == 1) {
                            bool m = true;
                            int count = 0;
                            cout << "После какого элемента вставить? ";
                            cin >> a;
                            for (int i = 0; i < n; i++) count++;
                            if (count == 0) {
                                cout << "такого элемента нет!\n";
                            } else {
                                cout << "Введите какое число вставить: ";
                                cin >> n1;
                                for (int i = 0; m != false; i++) {
                                    if (arr[i] == a) {
                                        arr.insert(arr.begin() + i+1, n1);
                                        m = false;
                                    }
                                }
                            }
                            
                        } else if (n == 2) {
                            bool m = true;
                            int count = 0;
                            cout << "До какого элемента вставить? ";
                            cin >> a;
                            for (int i = 0; i < n; i++) count++;
                            if (count == 0) {
                                cout << "такого элемента нет!\n";
                            } else {
                                cout << "Введите какое число вставить: ";
                                cin >> n1;
                                for (int i = 0; m != false; i++) {
                                    if (arr[i] == a) {
                                        arr.insert(arr.begin() + i, n1);
                                        m = false;
                                    }
                                }
                            }
                        } else {
                            f = false;
                        }
                        f = false;
                    } else {
                        cout << "введите число меньше, вы выходите за границы стека!\nДля отмены введите 0\n";
                    }
                } 
            }
        }

        void popStack() {
            int count1 = arr.size();
            if (arr.empty()) {
                cout << "\nстек пуст\n";
            } else {
                bool fl = true;
                int count, del;
                cout << "сколько элементов удалить? ";
                while (fl) {
                    cin >> count;
                    if (count <= count1) {
                        cout << "сохранить удаленный элемент в стек удаленных?\n1. Да\n2. Нет\n";
                        cin >> del;
                        if (del == 1) {
                            for (int i = 0; i < count; i++) {
                                int tmp = arr.back();
                                arr.pop_back();
                                dell.push_back(tmp);
                            }
                        } else {
                            for (int i = 0; i < count; i++) {
                                arr.pop_back();
                            }
                        }
                        fl = false;
                    } else {
                        cout << "невозможно удалить " << count << " элементов, в стеке всего " <<  arr.size() << " элементов\n";
                    }
                }
            }
        }

        void showDell() {
            if (!dell.empty()) {
                for(auto e : dell) cout << setw(3) << e;
                    cout << endl;
            } else {
                cout << "Стек удаленных пуст!\n";
            }
        }

};

void draw() {
    cout << "\n===============================================================\n";
}

void menu() {
    cout << "\n1. Проверка заполнености стека (количество)\n" \
    << "2. Поиск элемента с заданной информационной частью\n" \
    << "3. Дозаполнить стек (в конец)\n" \
    << "4. Удаление элемента из вершины стека\n" \
    << "5. Вывод текущего состояния стеков на экран\n";
}

int main() {
    // setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите количество элементов в стеке\n";
    cin >> n;
    Queue <int> S;
    S.push(n);
    bool fl = true;
    while (fl) {
        menu();
        int num;
        cin >> num;
        switch (num)
        {
        case 1:
            draw();
            S.size();
            break;
        case 2:
            draw();
            S.search(n);
            break;
        case 3:
            draw();
            S.push(n);
            break;
        case 4:
            draw();
            S.show();
            S.popStack();
            S.show();
            break;
        case 5:
            draw();
            S.show();
            draw();
            S.showDell();
            break;
        default:
            break;
        }
    }
}