# temporarily

1. [task 1-3](#task-1-3)
2. [task 4](#4-task)
3. [task 5](#task-5)

## task 1-3
```
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

```

## 4 task

```
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

```
## task 5

```
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#define N 10
char symbol;

struct student {
    string name;
    int number;
    int oc[7];
}st[N];

void stud_input(int i);
void stud_output(int i);
void student_oc(int i);
void search(int n);
void search2(int n);
void information();
void save(int n);
void read();
void merging();

int main() {
    setlocale(LC_ALL, "rus");
    int num_stud;
    int user;
    bool user_i = true;
    cout << "Введите число студентов: "; 
    cin >> num_stud;
    // system("cls");
        while (user_i != false) {
            information();
            cin >> user;
            if (user == 9)
                user_i = false;
            if (user == 1) {
                for (int i = 0; i < num_stud; i++) {
                    cout << "Ввод информации " << i + 1 << "-го студента" << endl;
                    stud_input(i);
                    // system("cls");
                }
            }
            if (user == 2) {
                for (int i = 0; i < num_stud; i++) {
                    stud_output(i);
                }
            }
            if (user == 3) {
                for (int i = 0; i < num_stud; i++) {
                    student_oc(num_stud);
                }
            }
            if (user == 4) {
                search(num_stud);
            }
            if (user == 5) {
                search2(num_stud);
            }
            if (user == 6)
                save(num_stud);
            if (user == 7)
                read();
            if (user == 8)
                merging();
        }
}

void stud_input(int i) {
    setlocale(LC_ALL, "rus");
    cout << "Введите имя студента: ";
    cin >> st[i].name;
    st[i].number = i;
    // system("cls");
    cout << "Введите  его оценки: ";
    for (int a = 0; a < 7; a++){
    cin >> st[i].oc[a];

    }
}

void stud_output(int i) {
    cout << "Студент " << i + 1;
    cout << endl << "Фамилия - " << st[i].name;
    cout << endl << "Оценки - " << st[i].oc[0] << " " << st[i].oc[1] << " " << st[i].oc[2] << " " << st[i].oc[3] << " " << st[i].oc[4] << " " << st[i].oc[5] << " " << st[i].oc[6] << endl;
}

void student_oc(int i) {
    int sum = 0, k = 0, mean;
    for (int a = 0; a < 7; a++) {
        if (st[i].oc[a] != 0) {
            sum += st[i].oc[a];
            k++;
        }
    }
    if (k != 0)
        mean = sum / k;
    cout << "Средний бал студента " << st[i].name << " равен " << mean << endl;
}

void search(int n) {
    cout << "Введите фамилию студента\n";
    string name;
    cin >> name;
    int f = 0;
    for (int i = 0; i < n; i++) {
        if (name == st[i].name) {
            f = 1;
            cout << "\nФамилия: " << st[i].name << '\n';
            cout << "оценки: " << st[i].oc[0] << " " << st[i].oc[1] << " " << st[i].oc[2] << " " << st[i].oc[3] << " " << st[i].oc[4] << " " << st[i].oc[5] << " " << st[i].oc[6] << endl;
        }
    }
    if (f == 0)
        cout << "студент с такой фамилией не найден\n";
}

void search2(int n) {
    cout << "Введите номер студента\n";
    int num;
    cin >> num;
    int f = 0;
    for (int i = 0; i < n; i++) {
        if (num - 1 == st[i].number) {
            f = 1;
            cout << "\nФамилия: " << st[i].name << '\n';
            cout << "оценки: " << st[i].oc[0] << " " << st[i].oc[1] << " " << st[i].oc[2] << " " << st[i].oc[3] << " " << st[i].oc[4] << " " << st[i].oc[5] << " " << st[i].oc[6] << endl;
        }
    }
    if (f == 0)
        cout << "студент под таким номером не найден\n";
}

void information() {
    cout << "\nЧто нужно вывести?\n" << \
            "1. ввод информации о студентах\n" << \
            "2. просмотр информации обо всех студентах\n" << \
            "3. подсчет среднего значения по оценкам\n" << \
            "4. поиск по фамилии\n" << \
            "5. поиск по номеру\n" << \
            "6. сохранить в файле\n" << \
            "7. прочитать из файла\n" << \
            "8. объединение двух файлов\n" << \
            "9. выход\n\n";
}

void save(int n) {
    ofstream fout;
    string str;
    printf("Введите название файла (без расширения)\n");
    cin >> str;
    string strtxt;
    strtxt = str + ".txt";
    fout.open(strtxt);
    for (int i = 0; i < n; i++) {
        fout << st[i].number << ' ' << st[i].name << ' ' << st[i].oc[0] << ' ' << st[i].oc[1] << ' ' << st[i].oc[2] << ' ' << st[i].oc[3] << ' ' << st[i].oc[4] << ' ' << st[i].oc[5] << ' ' << st[i].oc[6] << '\n';
    }
    fout.close();
}

void read() {
    ifstream fin;
    string str, s1, s = "\n";
    printf("Введите название файла (без расширения)\n");
    cin >> str;
    string strtxt;
    strtxt = str + ".txt";
    fin.open(strtxt);
    int size = 0;
    char ch;
    // char arr[1000];
    while (fin >> ch) {
        size++;
    }
    if (size == 0) {
        cout << "\nТакого файла нет\n";
    } 
    fin.close();
    if (size > 0) {
        ifstream f(strtxt);
        // for (int i = 0; i < size; i++) {
        //     f >> arr[i];
        //     cout << arr[i];
        // }
        // cout << '\n';
        while (!f.eof()) {
            while (getline(f, s1)) {
                s += s1;
            }
            s += '\n';
        }
        cout << s;
        f.close();
    }
}

void merging() {
    ifstream fin;
    string str, str2, s1, s = "\n";
    printf("Введите название 1 файла (без расширения)\n");
    cin >> str;
    string strtxt;
    strtxt = str + ".txt";
    fin.open(strtxt);
    int size = 0;
    char ch;
    // char arr[1000];
    while (fin >> ch) {
        size++;
    }
    if (size == 0) {
        cout << "\nТакого файла нет\n";
    } 
    fin.close();
    ifstream fin2;
    printf("Введите название 2 файла (без расширения)\n");
    cin >> str2;
    string strtxt2;
    strtxt2 = str2 + ".txt";
    fin2.open(strtxt2);
    int size2 = 0;
    char ch2;
    while (fin2 >> ch2) {
        size2++;
    }
    if (size2 == 0) {
        cout << "\nТакого файла нет\n";
    } 
    fin2.close();
    if (size > 0 && size2 > 0) {
        ifstream f(strtxt);
        ifstream f2(strtxt2);
        string strres;
        cout << "введите название файла, в который будут записаны данные из двух файлов (без расширения)\n";
        cin >> strres;
        strres += ".txt";
        ofstream fout(strres);
        while (!f.eof()) {
            while (getline(f, s1)) {
                s += s1;
                fout << s;
                s = '\n';
            }
        }
        fout << '\n';
        while (!f2.eof()) {
            while (getline(f2, s1)) {
                s += s1;
                fout << s;
                s = '\n';
            }
        }
        fout.close();
        f2.close();
        f.close();
    }
}
```