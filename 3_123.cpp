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
    int count1 = vect.size();
    int count2 = vect2.size();
    if (vect.empty() && vect2.empty()) {
        cout << "\nстек 1 пуст\n";
        cout << "\nстек 2 пуст\n";
    } else if (count1 < num && count2 < num) {
        cout << "1) невозможно удалить " << num << " элементов, в стеке всего " <<  vect.size() << " элементов\n";
        cout << "2) невозможно удалить " << num << " элементов, в стеке всего " <<  vect2.size() << " элементов\n";
    } else {
        for (int i = 0; i < num; i++) {
            vect.pop_back();
            vect2.erase(vect2.begin());
        }
    }
            
}

template<class T> void St<T>::show()
{
    if (vect.empty()) {
        cout << "\nстек 1 пуст\n";
    } else {
        cout<<"1) элементы стека: ";
        for(auto e : vect) cout << setw(3) << e;
        cout << endl;
    }
    if (vect2.empty()) {
        cout << "\nстек 2 пуст\n";
    } else {
        cout<<"2) элементы стека: ";
        for(auto e : vect2) cout << setw(3) << e;
        cout << endl;
    }
}

template<class T> void St<T>::add()
{
    int a;
    cin >> a;
    vect.push_back(a);
    vect2.insert(vect2.begin(), a);
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

// void add (std::vector<int>& vec){
//     int n;
//     cin >> n;
//     vec.push_back(n);
// }

// void addRev (std::vector<int>& vec){
//     int n;
//     cin >> n;
//     vec.insert(vec.begin(), n);
// }

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
                        vect2.insert(vect2.begin(), a);
                        
                    }
                } else if (n1 == 2) {
                    for (int i = 0; i < n; i++) {
                        a = rand() & 10;
                        vect.push_back(a);
                        vect2.insert(vect2.begin(), a);
                    }
                }
                f = false;
            } else if (n == 0) {
                f = false;
            } else {
                cout << "введите число меньше, вы выходите за границы стека!\nДля отмены введите 0\n";
            }
        }
        // cout << " D U M P      COUNT = " << n + size0 << '\n';
    }
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
            S.empty();
            break;
        case 2:
            S.size();
            break;
        case 3:
            S.stackPush(n);
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
        default:
            break;
        }
    }
}

