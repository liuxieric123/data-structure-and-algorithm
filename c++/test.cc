#include <iostream>

using std::cout;

int main() {
    int a = -1;
    unsigned b = 4294967295;
    cout << (static_cast<unsigned>(a));
    cout << (static_cast<int>(b));
}