#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int rec(int n);

int main() {
    cout << rec(2254) - rec(2252);
}

int rec(int n) {
    if (n < 4)
        return 1;
    if (n > 3 && (n % 2 == 1))
        return n;
    if (n > 3 && (n % 2 == 0))
        return rec(n-1) + rec(n-2) + rec(n-3);
    return rec(n);
}
