#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int rec(long long int n);

int main() {
    cout << rec(12345) * (rec(10) - rec(12)) / rec(11) + rec(10101);
}

int rec(long long int n) {
    if (n > 10000)
        return n - 10000;
    if (n >= 1 && n <= 10000)
        return rec(n+1) + rec(n+2);
    return rec(n);
}
