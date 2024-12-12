#include<iostream>
using namespace std;

int power(int a, int p) {
    if (p == 0) {
        return 1;
    }
    if (p == 1) {
        return a;
    }

    if (p % 2 == 0 ) {
        return power(a , p / 2) * power(a , p / 2);
    } else {
        return a * power(a, p / 2) * power(a , p / 2);
    }
}

int main() {
    int a = 2;
    int p = 6;
    cout << power(a, p);
    return 0;
}