## 右值与完美转发

来自 [从4行代码看右值引用](https://www.cnblogs.com/qicosmos/p/4283455.html)

![从4行代码看右值引用](./img/&&.png)

完美转发是一种机制，其作用是在函数模板里将参数以原始的左值或右值属性传递给其他函数，不会造成额外的复制或移动操作。完美转发借助引用折叠和std::forward来实现

```cpp
#include <iostream>
#include <utility>

// 被转发的函数
void printValue(int& value) {
    std::cout << "Lvalue: " << value << std::endl;
}

void printValue(int&& value) {
    std::cout << "Rvalue: " << value << std::endl;
}

// 转发函数模板
template<typename T>
void forwardValue(T&& value) {
    printValue(std::forward<T>(value));
}

int main() {
    int x = 10;
    forwardValue(x); // 传递左值
    forwardValue(20); // 传递右值

    return 0;
}
```
