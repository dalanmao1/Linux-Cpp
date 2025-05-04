#include <iostream>
using namespace std;

template <class T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}
int maxValue(double a, double b) = delete; //T = double禁止使用

int main() {
    cout << maxValue(3, 5) << endl;       // T = int，输出 5
    cout << maxValue(2.7, 1.2) << endl;    // T = double，输出 2.7
    cout << maxValue('a', 'z') << endl;    // T = char，输出 'z'
    return 0;
}