#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
const int N = 10;

void menu() {
    cout << "\n1. Проверка пустоты стека\n" \
    << "2. Проверка заполнености стека (количество)\n" \
    << "3. Дозаполнить стек\n" \
    << "4. Удаление элемента из вершины стека\n" \
    << "5. Вывод текущего состояния стека на экран\n";
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
        void stackPush(T);
        void pop2(T);
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

template<class T> void St<T>::pop2(T num)
{
    int count1 = vect.size();
    if (vect.empty()) {
        cout << "\nстек пуст\n";
    } else if (count1 < num) {
        cout << "невозможно удалить " << num << " элементов, в стеке всего " <<  vect.size() << " элементов\n";
    } else {
        for (int i = 0; i < num; i++) {
            vect.pop_back();
        }
    }
            
}

template<class T> void St<T>::show()
{
    if (vect.empty()) {
        cout << "\nстек пуст\n";
    } else {
        cout<<"элементы стека: ";
        for(auto e : vect) cout << setw(3) << e;
        cout << endl;
    }
}

template<class T> void St<T>::add()
{
    int a;
    cin >> a;
    vect.push_back(a);
}

template<class T> void St<T>::size()
{
    if (vect.empty()) {
        cout << "\nстек пуст\n";
    } else {
        T count = vect.size();
        cout << "\n Количество элементов в стеке = " << count << endl;
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

template<class T> void St<T>::stackPush(T num)
{
    bool f = true;
    int n, a, n1;
    int size0 = vect.size();
    if (size0  >= num) {
        cout << "Заполнение стека невозможно, иначе он будет переполнен!\n";
    } else {
        cout << "\nВведите сколько элементов внести в стек: ";
        while (f) {
            cin >> n;
            if (n <= num - size0) {
                cout << "Как заполнить стек?\n" << "1. Вручную\n" << "2. Рандомом\n" << "3. не заполнять\n";
                cin >> n1;
                if (n1 == 1) {
                    for (int i = 0; i < n; i++) {
                        cin >> a;
                        vect.push_back(a);
                        
                    }
                } else if (n1 == 2) {
                    for (int i = 0; i < n; i++) {
                        a = rand() & 10;
                        vect.push_back(a);
                    }
                }
                f = false;
            } else if (n == 0) {
                f = false;
            } else {
                cout << "введите число меньше, вы выходите за границы стека!\nДля отмены введите 0\n";
            }
        }
    }
}


void draw() {
    cout << "\n===============================================================\n";
}

int main() {
    St <int> S;
    int n;
    cout << "Введите количество элементов в стеке\n";
    cin >> n;
    S.stackPush(n);
    bool fl = true;
    while (fl) {
        menu();
        int num, nn;
        cin >> num;
        switch (num)
        {
        case 1:
            draw();
            S.empty();
            break;
        case 2:
            draw();
            S.size();
            break;
        case 3:
            draw();
            S.stackPush(n);
            draw();
            S.show();
            break;
        case 4:
            draw();
            cout << "сколько элементов удалить?\n";
            cin >> nn;
            if (nn == 1)
                S.pop();
            else S.pop2(nn);
            S.show();
            break;
        case 5:
            draw();
            S.show();
            break;
        default:
            break;
        }
    }
}

