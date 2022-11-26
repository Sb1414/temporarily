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
    vector<int> revarr;

public:

    void size() {
        if (arr.empty()) {
            cout << "\nсписок пуст\n";
        }
        else {
            T count = arr.size();
            cout << "\n Количество элементов в списке = " << count << endl;
        }
    }

    void push(int num) {
        bool f = true, fdel = true;
        int n, a, n1, delOrNot;
        int size0 = arr.size();
        if (size0 >= num) {
            cout << "Заполнение списка невозможно, иначе он будет переполнен!\n";
        }
        else {
            while (fdel) {
                cout << "как заполнить?\n1. Новыми данными\n2. Из списка удаленных\n";
                cin >> delOrNot;
                if (delOrNot == 1) {
                    cout << "\nВведите сколько элементов внести в стек: ";
                    while (f) {
                        cin >> n;
                        if (n <= num - size0) {
                            cout << "Как заполнить список?\n" << "1. Вручную\n" << "2. Рандомом\n" << "3. не заполнять\n";
                            cin >> n1;
                            if (n1 == 1) {
                                for (int i = 0; i < n; i++) {
                                    cin >> a;
                                    arr.push_back(a);
                                    revarr.insert(revarr.begin() + 1, a);
                                }
                            }
                            else if (n1 == 2) {
                                for (int i = 0; i < n; i++) {
                                    a = 1 + rand() % 10;
                                    arr.push_back(a);
                                    revarr.insert(revarr.begin() + 1, a);
                                }
                            }
                            newSize += n;
                            f = false;
                        }
                        else if (n == 0) {
                            f = false;
                        }
                        else {
                            cout << "введите число меньше, вы выходите за границы стека!\nДля отмены введите 0\n";
                        }
                    }
                    fdel = false;
                }
                else if (delOrNot == 2) {
                    if (dell.size() > 0) {
                        int tmp = dell.back();
                        arr.push_back(tmp);
                        revarr.insert(revarr.begin() + 1, tmp);
                        dell.erase(dell.begin()+dell.size()-1);
                        cout << "\nэлемент " << tmp << " добавлен в список\n";
                    } else {
                        cout << "Список удаленных пуст, заполнение данным способом невозможно!\n";
                    }
                    fdel = false;
                }
            }

        }
    }

    void pop() {
        int num = arr.size();
        int isc, n, res;
        cout << "как удалить?\n1. По индексу\n2. Заданный элемент\n3. Отмена, не удалять\n";
        cin >> isc;
        if (isc == 1) {
            cout << "Введите № элемента (отсчет с 1): ";
            cin >> n;
            if (n == 1) {
                cout << "\nУдаление заголовочного элемента запрещено!\n\n";
            } else if (n > 1 && n <= num) {
                arr.erase(arr.begin() + n - 1);
                revarr.erase(revarr.begin() + n - 1);
            } else {
                cout << "число выходит за пределы\n";
            }
        }
        else if (isc == 2) {
            int c = 0, ss =arr.size();
            cout << "Введите элемент: ";
            cin >> n;
            try {
                for (int i = 0; i < num; i++) {
                    if (arr[i] == n) c++;
                }
                if (c == 1 && arr[0] == n) {
                    cout << "это заголовочный элемент, его нельзя удалять!\n";
                } else if (c > 1) {
                    cout << "Таких элементов больше одного! Что делать?\n1. Удалить все повторения\n2. Удалить первое\n3. Удалить последнее\n";
                    int tmp;
                    cin >> tmp;

                    if (tmp == 1) {
                        cout << "\nСохранить удаленный элементы в список удаленных?\n1. Да\n2. Нет\n";
                        cin >> res;
                        if (res == 1) {
                            for (int i = 1; i < ss; i++)
                                if (arr[i] == n) {
                                    dell.push_back(n);
                                    arr.erase(arr.begin() + i);
                                    revarr.erase(revarr.begin() + i);
                                }
                        }
                        else {
                            for (int i = 1; i < ss; i++)
                                if (arr[i] == n) {
                                    arr.erase(arr.begin() + i);
                                    revarr.erase(revarr.begin() + i);
                                    // revarr.erase(revarr.begin() + num-(i)); // если будет падать, то -1
                                }
                        }

                    }
                    else if (tmp == 2) {
                        bool m = true;
                        cout << "\nСохранить удаленный элементы в список удаленных?\n1. Да\n2. Нет\n";
                        cin >> res;
                        if (res == 1) {
                            dell.push_back(n);
                        }
                        else {
                            for (int i = 1; m == true; i++) {
                                if (arr[i] == n) {
                                    arr.erase(arr.begin() + i);
                                    // revarr.erase(revarr.begin() + num-(i)); // если будет падать, то -1
                                    revarr.erase(revarr.begin() + i);
                                    m = false;
                                }
                            }
                        }
                    }
                    else if (tmp == 3) {
                        int c1 = 0; 
                        cout << "\nСохранить удаленный элементы в список удаленных?\n1. Да\n2. Нет\n";
                        cin >> res;
                        if (res == 1) {
                            dell.push_back(n);
                        }
                        else {
                            for (int i = 0; c1 != c; i++) {
                                if (arr[i] == n) c1++;
                                if (c1 == c) {
                                    arr.erase(arr.begin() + i);
                                    revarr.erase(revarr.begin() + i);
                                    // revarr.erase(revarr.begin() + num-(i)); // если будет падать, то -1
                                } 
                            }
                        }
                    }
                    else {
                        cout << "ничего не выбрано!\n";
                    }
                }
                else if (c == 1) {
                    cout << "\nСохранить удаленный элементы в список удаленных?\n1. Да\n2. Нет\n";
                    cin >> res;
                    if (res == 1) {
                        dell.push_back(n);
                    }
                    for (int i = 0; i < num; i++) {
                        if (arr[i] == n) {
                            arr.erase(arr.begin() + i);
                            revarr.erase(revarr.begin() + i);
                            // revarr.erase(revarr.begin() + num-(i)); // если будет падать, то -1
                        }
                    }               
                }
                else {
                    cout << "число не найдено!\n";
                }
            }
            catch (int x)
            {
                cout << "Некорректный ввод\n" << '\n';
            }
        }
    }

    void show() {
        if (arr.empty()) {
            cout << "Списки пусты\n";
        }
        else {
            cout << "Прямой список:   ";
            for (auto e : arr) cout << setw(4) << e;
            cout << endl;

            cout << "Обратный список: ";
            for(auto e : revarr) cout << setw(4) << e;
                cout << endl;
        }
        if (dell.empty()) {
            cout << "Список удаленных пуст\n";
        }
        else {
            cout << "Список удаленных: \n";
            for (auto e : dell) cout << setw(4) << e;
            cout << endl;
        }
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
                if (arr[i] == n) cout << setw(3) << i + 1;
            }
            if (c > 0) cout << " <- индекс\n";
            if (c == 0) {
                cout << "число не найдено\n";
            }
        }
        catch (int x)
        {
            cout << "Некорректный ввод" << '\n';
        }
    }

    void insert(int num) {
        bool f = true;
        int n, a, n1;
        int size0 = arr.size();
        if (size0 >= num - 1) {
            cout << "Заполнение списка невозможно, иначе он будет переполнен!\n";
        }
        else {
            cout << "\nВнести ПОСЛЕ (введите 1) или ДО (введите 2) заданного элемента?: ";
            while (f) {
                cin >> n;
                if (n <= num - size0) {
                    if (n == 1) {
                        bool m = true;
                        int count = 0;
                        cout << "После какого элемента вставить?  ";
                        cin >> a;
                        a--;
                        for (int i = 0; i < n; i++) count++;
                        if (count == 0) {
                            cout << "такого элемента нет!\n";
                        }
                        else {
                            cout << "Введите какое число вставить: ";
                            cin >> n1;
                            for (int i = 0; m != false; i++) {
                                if (arr[i] == a) {
                                    arr.insert(arr.begin() + i + 1, n1);
                                    revarr.insert(revarr.begin() + i + 1, n1);
                                    m = false;
                                }
                            }
                        }

                    }
                    else if (n == 2) {
                        bool m = true;
                        int count = 0;
                        cout << "До какого элемента вставить? ";
                        cin >> a;
                        a--;
                        if (a == 0) {
                            cout << "\nЭто заголовочный элемент, перед ним нельзя ничего вставлять\n";
                        }
                        else {
                            for (int i = 0; i < n; i++) count++;
                            if (count == 0) {
                                cout << "такого элемента нет!\n";
                            }
                            else {
                                cout << "Введите какое число вставить: ";
                                cin >> n1;
                                for (int i = 0; m != false; i++) {
                                    if (arr[i] == a) {
                                        arr.insert(arr.begin() + i, n1);
                                        revarr.insert(revarr.begin() + i, n1);
                                        m = false;
                                    }
                                }
                            }
                        }
                    }
                    else {
                        f = false;
                    }
                    f = false;
                }
                else {
                    cout << "введите число меньше, вы выходите за границы списка!\nДля отмены введите 0\n";
                }
            }
        }
    }

    void header(int num) {
        if (num > 1) {
            int m;
            cout << "введите заголовочный элемент: ";
            cin >> m;
            arr.push_back(m);
            revarr.push_back(m);
        }
    }

    void resetRevArr() {
        cout << "С сохранение заголовочного элемента? (1. Да / 2. Нет): ";
        int number, count = arr.size();
        cin >> number;
        switch (number)
        {
        case 1:
            revarr.clear();
            revarr.push_back(arr[0]);
            for (int i = 1; i < count; i++) {
                revarr.push_back(arr[count - i]);
            }
            break;
        case 2:
            revarr.clear();
            for (int i = 0; i < count; i++) {
                revarr.push_back(arr[count - i - 1]);
            }
            break;
        default:
            break;
        }
        
    }

};

void draw() {
    cout << "\n===============================================================\n";
}

void menu() {
    cout << "\n1. Проверка заполнености списков (количество)\n" \
        << "2. Поиск элемента с заданной информационной частью\n" \
        << "3. Дозаполнить список (в конец)\n" \
        << "4. Дозаполнить список (после заданного / перед заданным)\n"
        << "5. Удаление заданного элемента из списка\n" \
        << "6. Вывод текущего состояния списка на экран\n"\
        << "7. Переписать (обновить) обратный массив\n";
}

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите количество элементов в очереди\n";
    cin >> n;
    Queue <int> S;
    S.header(n);
    draw();
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
            S.push(n - 1);
            S.show();
            break;
        case 4:
            draw();
            S.show();
            S.insert(n);
            S.show();
            break;
        case 5:
            draw();
            S.show();
            S.pop();
            S.show();
            break;
        case 6:
            draw();
            S.show();
            break;
        case 7:
            draw();
            S.resetRevArr();
            S.show();
        default:
            break;
        }
    }
}