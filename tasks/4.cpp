#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <iomanip>

const int Rows = 10;   // столбцы
const int Columns = 8; // строки 

using namespace std;

void painting(int g, int r);
void nameArray(int num);
void input(int** arr);
void colors(int x);
void serch(int **arr, int x);

int main() {
    int** arr = new int* [Columns];  // динамическиое выделение памяти под массив
    for (int i = 0; i < Columns; i++) {
        arr[i] = new int[Rows];
    }

    nameArray(1);
    painting(Rows, 3);
    input(arr);
    painting(Rows, 3);

    int num;
    cout << "enter the number you want to find: ";
    cin >> num;

    if (!(int)num) {
        colors(12);
        cout << "\nERROR: not a number\n";
        colors(7);
    } else {
        serch(arr, num);
    }

    for (int i = 0; i < Columns; i++) {
        delete[]arr[i];
    }
    delete[]arr;
}

void input(int** arr) {
    for (int i = 0; i < Columns; i++) {
        for (int j = 0; j < Rows; j++) {
            if (j == 0) cout << "|";
            arr[i][j] = rand() % 15;
            cout << setw(3) << arr[i][j];
            if (j == Rows - 1) {
                cout << "  |";
            }
        }
        cout << '\n';
    }
}

void serch(int **arr, int x) {
    bool f = true;
    int ox = -1, oy = -1;
    for (int i = 0; i < Columns; i++) {
        for (int j = 0; j < Rows; j++) {
            if (arr[i][j] == x && f) {
                oy = i; ox = j;
                f = false;
            }
        }
    }
    if (ox != -1) {
        colors(11);
        cout << "the element " << x << " is located at the given coordinates [" << ox+1 << "][" << oy+1 << "]\n";
        colors(7);
    } else {
        colors(12);
        cout << "number not found";
        colors(7);
    }
}

// смена цвета в консоли
void colors(int x) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

// рамочка
void painting(int g, int r) {
    int f = 0;
    cout << " ";
    while (f != r * g + 1) {
        cout << "-";
        f++;
    }
    cout << endl;
}

// какой это массив
void nameArray(int num) {
    painting(8, 2);
    if (num == 1) cout << "|  SOURSE  ARRAY  |" << endl;
    else cout << "|    SUBARRAY     |" << endl;
    painting(8, 2);
}
