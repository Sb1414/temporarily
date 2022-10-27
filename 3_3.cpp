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
    << "6. Дозаполнить стек\n";
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
        void stackPush();
        void pop2(T);
    private:
        vector<T> vect;
        vector<T> vect2;
};

template<class T> void St<T>::push(T num)
{
    if (vect.empty()) {
        cout << "\nстек 1 пуст\n";
    } else {
        vect.push_back(num);
    }
    if (vect2.empty()) {
        cout << "\nстек 2 пуст\n";
    } else {
        vect2.insert(vect2.begin(), num);
    }
}

template<class T> void St<T>::pop()
{
    if (vect.empty()) {
        cout << "\nстек 1 пуст\n";
    } else {
        cout << "1) удален элемент: " << vect.back() << endl;
        vect.pop_back();
    }
    if (vect2.empty()) {
        cout << "\nстек 2 пуст\n";
    } else {
        // int nnn = vect2.begin(0);
        // cout << "2) удален элемент: " << nnn << endl;
        vect2.erase(vect2.begin());
    }
}

template<class T> void St<T>::pop2(T num)
{
    if (vect.empty()) {
        cout << "\nстек 1 пуст\n";
    } else if (vect.back() < num) {
        cout << "1) невозможно удалить " << num << " элементов, в стеке всего " <<  vect.size() << " элементов\n";
    } else {
        for (int i = 0; i < num; i++)
            vect.pop_back();
    }
    if (vect2.empty()) {
        cout << "\nстек 2 пуст\n";
    } else if (vect2.back() < num) {
        cout << "2) невозможно удалить " << num << " элементов, в стеке всего " <<  vect2.size() << " элементов\n";
    } else {
        for (int i = 0; i < num; i++)
            vect2.erase(vect2.begin());
    }
}

template<class T> void St<T>::show()
{
    if (vect.empty()) {
        cout << "\nстек 1 пуст\n";
    } else {
        cout<<"1) элементы стека: ";
        for(auto e : vect) cout << e <<" ";
        cout << endl;
    }
    if (vect2.empty()) {
        cout << "\nстек 2 пуст\n";
    } else {
        cout<<"2) элементы стека: ";
        for(auto e : vect2) cout << e <<" ";
        cout << endl;
    }
}

template<class T> void St<T>::add()
{
    int n1;
    if (vect.empty()) {
        cout << "\nстек 1 пуст\n";
    } else {
        cout << "\nВведите число, которое нужно вставить в стек: ";
        cin >> n1;
        vect.push_back(n1);
    }
    if (vect2.empty()) {
        cout << "\nстек 2 пуст\n";
    } else {
        vect2.insert(vect2.begin(), n1);
    }
}

template<class T> void St<T>::size()
{
    if (vect.empty()) {
        cout << "\nстек 1 пуст\n";
    } else {
        T count = vect.size();
        cout << "\n1) Количество элементов в стеке = " << count << endl;
    }
    if (vect2.empty()) {
        cout << "\nстек 2 пуст\n";
    } else {
        T count = vect2.size();
        cout << "\n2) Количество элементов в стеке = " << count << endl;
    }
}

template<class T> void St<T>::empty()
{
    if (vect.empty()) {
        cout << "\nстек 1 пуст\n";
    } else {
        cout << "\nстек 1 не пуст\n";
    }
    if (vect.empty()) {
        cout << "\nстек 2 пуст\n";
    } else {
        cout << "\nстек 2 не пуст\n";
    }
}

template<class T> void St<T>::stackPush()
{
    int n, a, n1;
    cout << "\nВведите количество элементов в стеке: ";
    cin >> n;
    cout << "Как заполнить стек?\n" << "1. Вручную\n" << "2. Рандомом\n" << "3. не заполнять\n";
    cin >> n1;
    if (n1 == 1) {
        for (int i = 0; i < n; i++) {
            cin >> a;
            vect.push_back(a);
            vect2.insert(vect2.begin(), a);
        }
    } else if (n1 == 2) {
        for (int i = 0; i < n; i++) {
            a = rand() & 10;
            vect.push_back(a);
            vect2.insert(vect2.begin(), a);
        }
    }
}

int main() {
    St <int> S;
    S.stackPush();
    bool fl = true;
    while (fl) {
        system("cls");
        menu();
        int num, nn;
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
            cout << "сколько элементов удалить?\n";
            cin >> nn;
            if (nn == 1)
                S.pop();
            else S.pop2(nn);
            break;
        case 5:
            S.show();
            break;
        case 6:
            S.stackPush();
            break;
        default:
            break;
        }
    }
}

