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
        // int * arr;  // массив-буфер
        int sizeQueue; // размер буфера
        int newSize; // размер заполенной очереди
        vector<int> arr;

    public:
        // ~Queue() // деструктор
        // {
        //     delete[] arr;
        // }
        void firstpush(int n) {
            sizeQueue = n;
            for ( int i = 0; i < sizeQueue; ++i ) // заполняем буфер нулями*
                arr.push_back(0);
            newSize = 0;
        }

        void empty() {
            newSize = 0;
            for ( int i = 0; i < sizeQueue; ++i ) {
                if (arr[i] != 0) {
                    newSize++;
                }
            }
            if (newSize == 0) cout << "Очередь пуста\n";
            else cout << "Очередь не пуста\n";
        }

        void size() {
            newSize = 0;
            for ( int i = 0; i < sizeQueue; ++i ) {
                if (arr[i] != 0) {
                    newSize++;
                }
            }
            if (newSize == 0) cout << "Очередь пуста\n";
            else cout << "В очереди " << newSize << " элементов\n";
        }

        void push(int num) {
            // cout << " D U M P     " << newSize << '\n';
            bool f = true;
            int n, a, n1;
            int size0 = newSize;
            if (size0  >= num) {
                cout << "Заполнение очереди невозможно, иначе она будет переполнена!\n";
            } else {
                cout << "\nВведите сколько элементов внести в очередь: ";
                while (f) {
                    cin >> n;
                    if (n <= num - size0) {
                        cout << "Как заполнить очередь?\n" << "1. Вручную\n" << "2. Рандомом\n" << "3. не заполнять\n";
                        cin >> n1;
                        if (n1 == 1) {
                            for (int i = 0; i < n; i++) {
                                cin >> a;
                                arr.erase(arr.end() - 1);
                                arr.insert(arr.begin() + i + newSize, a);
                            }
                        } else if (n1 == 2) {
                            for (int i = 0; i < n; i++) {
                                a = 1 + rand() % 10;
                                arr.erase(arr.end() - 1);
                                arr.insert(arr.begin() + i + newSize, a);
                            }
                        }
                        newSize += n;
                        f = false;
                    } else if (n == 0) {
                        f = false;
                    } else {
                        cout << "введите число меньше, вы выходите за границы очереди!\nДля отмены введите 0\n";
                    }
                }
                // cout << " D U M P      COUNT = " << n + size0 << '\n';
            }
        }

        void pop() {
            arr.erase(arr.begin());
            arr.push_back(0);
            newSize -= 1;
        }

        void pop2(int num) {
            for (int i = 0; i < num; i++) {
                arr.erase(arr.begin());
                arr.push_back(0);
            }
            newSize -= num;
        }

        void show() {
            // for ( int i = 0; i < sizeQueue; ++i )
            //     cout << setw(3) << arr[i];
            for(auto e : arr) cout << setw(3) << e;
                cout << endl;
        }

};

void draw() {
    cout << "\n===============================================================\n";
}

void menu() {
    cout << "\n1. Проверка пустоты очереди\n" \
    << "2. Проверка заполнености очереди (количество)\n" \
    << "3. Дозаполнить очередь\n" \
    << "4. Удаление элемента из начала очереди\n" \
    << "5. Вывод текущего состояния очереди на экран\n";
}

int main() {
    // setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите количество элементов в очереди\n";
    cin >> n;
    Queue <int> S;
    S.firstpush(n);
    S.push(n);
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
            S.push(n);
            break;
        case 4:
            draw();
            cout << "сколько элементов удалить?\n";
            cin >> nn;
            if (nn == 1)
                S.pop();
            else S.pop2(nn);
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
