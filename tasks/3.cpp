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
int maxArr(int marr);
void input(int** arr);
void abbreviated(int** arr, int left, int right);
int maxInX(int inX);
int maxInY(int inY);
int ret();

int main() {
    bool flag = true;
    int** arr = new int* [Columns];  // динамическиое выделение памяти под массив
    for (int i = 0; i < Columns; i++) {
        arr[i] = new int[Rows];
    }

    nameArray(1);
    painting(Rows, 3);
    input(arr);
    painting(Rows, 3);

    int left, right;
    cout << "Enter the left border of the array (a number greater than 0): ";
    cin >> left;
    printf("Enter the right border of the array (a number less than %d): ", Rows);
    cin >> right;

    if (!(int)left || !(int)right) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "\nERROR: not a number\n";
        ret();
        flag = false;
    } else if (right <= left) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "\nERROR: the right face is less than or equal to the left!";
        ret();
        flag = false;
    } else if  (flag) {
        abbreviated(arr, left, right);
    }

    for (int i = 0; i < Columns; i++) {
        delete[]arr[i];
    }
    delete[]arr;
}

// void errors(int left, int right) {

// }

void input(int** arr) {
    for (int i = 0; i < Columns; i++) {
        for (int j = 0; j < Rows; j++) {
            if (j == 0) cout << "|";
            arr[i][j] = rand() % 15;
            // cout << arr[i][j] << ' ';
            cout << setw(3) << arr[i][j];
            if (j == Rows - 1) {
                cout << "  |";
            }
        }
        cout << '\n';
    }
}

void abbreviated(int** arr, int left, int right) {
    int len = right - left;
    int max = arr[left - 1][0];
    int maxinX = 0, maxinY = 0;
    nameArray(2);
    painting(len + 1, 3);
    for (int i = 0; i < Columns; i++) {
        int l = left - 1;
        for (int j = 0; j <= len; j++) {
            if (j == 0) cout << "|";
            // cout << arr[i][l] << ' ';
            cout << setw(3) << arr[i][l];
            if (arr[i][l] > max) {
                max = arr[i][l];
                maxinX = i+1, maxinY = l-left+2;
            }
            l++;
            if (j == len) {
                cout << "  |";
            }
        }
        cout << '\n';
    }
    painting(len + 1, 3);
    maxArr(max);
    cout << "\nCoordinates: [" << maxinX << "][" << maxinY << "]\n";
    maxInX(maxinX);
    maxInY(maxinY);
}

int ret() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // для возврата белого текста
    cout << " ";
    return 0;
}

int maxInX(int inX) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "\nMaximum X = " << inX;
    return 0;
}

int maxInY(int inY) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "\nMaximum Y = " << inY;
    ret();
    return 0;
}

int maxArr(int marr) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout << "MAXIMUM = " << marr << endl;
    return 0;
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
