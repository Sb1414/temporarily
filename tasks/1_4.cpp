#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int rec(long long int n);
int factorial(int x);

int main() {
    cout << 1000 * rec(7) / rec(4);
}

int rec(long long int n) {
    if (n >= 5000)
        return factorial(n);
    if (n >= 1 && n <= 5000)
        return 2 * rec(n+1) / (n+1);
    return rec(n);
}

int factorial(int x) {
    int i = 1;
    while (x >= 1) {
        i = i * x;
        x -= 1;
    }
    return i;
}
