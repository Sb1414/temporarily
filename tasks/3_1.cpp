#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 10;

void menu() {
    cout << "\n1. Проверка пустоты стека\n" \
    << "2. Проверка заполнености стека (количество)\n" \
    << "3. Добавление элемента в вершину стека\n" \
    << "4. Удаление элемента из вершины стека\n" \
    << "5. Вывод текущего состояния стека на экран\n" \
    << "6. Заполнить стек\n";
}

template<typename T>
class St
{
    public:
        void push(T);
        void pop();
        void show();
        void add();
        void size();
        void empty();
    private:
        vector<T> vect;
};

template<class T> void St<T>::push(T num)
{
    if (vect.empty()) {
        cout << "\nстек пуст\n";
    } else {
        vect.push_back(num);
    }
}

template<class T> void St<T>::pop()
{
    if (vect.empty()) {
        cout << "\nстек пуст\n";
    } else {
        cout << "удален элемент: " << vect.back() << endl;
        vect.pop_back();
    }
}

template<class T> void St<T>::show()
{
    if (vect.empty()) {
        cout << "\nстек пуст\n";
    } else {
        cout<<"элементы стека: ";
        for(auto e : vect) cout << e <<" ";
        cout << endl;
    }
}

template<class T> void St<T>::add()
{
    if (vect.empty()) {
        cout << "\nстек пуст\n";
    } else {
        cout << "\nВведите число, которое нужно вставить в стек: ";
        int n1;
        cin >> n1;
        vect.push_back(n1);
    }
}

template<class T> void St<T>::size()
{
    if (vect.empty()) {
        cout << "\nстек пуст\n";
    } else {
        T count = vect.back();
        cout << "\nКоличество элементов в стеке = " << count << endl;
    }
}

template<class T> void St<T>::empty()
{
    if (vect.empty()) {
        cout << "\nстек пуст\n";
    } else {
        cout << "\nстек не пуст\n";
    }
}

int main() {
    St <int> S;
    cout << "\nДля заполнения стека нажмите 1\n";
    int n, a;
    cin >> n;
    if (n == 1) {
        for (int i = 0; i < 6; i++) {
            cin >> a;
            S.push(a);
        }
    }
    menu();
    bool fl = true;
    while (fl) {
        system("cls");
        menu();
        int num;
        cin >> num;
        switch (num)
        {
        case 1:
            S.empty();
            break;
        case 2:
            S.size();
            break;
        case 3:
            S.add();
            break;
        case 4:
            S.pop();
            break;
        case 5:
            S.show();
            break;
        case 6:
            cout << "\nВведите количество элементов в стеке: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> a;
                S.push(a);
            }
        default:
            break;
        }
    }
}

