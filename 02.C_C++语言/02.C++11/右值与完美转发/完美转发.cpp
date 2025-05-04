#include <iostream>
#include <utility>

// 被转发的函数
void printValue(int& value) {
    std::cout << "Lvalue: " << value << std::endl;
}

void printValue(int&& value) {
    std::cout << "Rvalue: " << value << std::endl;
}

//转发函数模板
template<typename T>
void forwardValue(T&& value) {
    printValue(std::forward<T>(value));
}

int main() {
    int x = 10;
    printValue(x); // 传递左值
    printValue(20); // 传递右值

    return 0;
}