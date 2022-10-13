#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int rec(int n);

int main() {
    cout << rec(1900);
}

int rec(int n) {
    if (n == 1)
        return 2;
    if (n > 1)
        return 2 * rec(n-1);
    return rec(n);
}