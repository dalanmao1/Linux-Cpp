
#include <iostream>

class MyString {
    public:
        explicit MyString(const char* s) {}  // 必须显式调用
    };
    
    void printStr(MyString s) {}
    
    int main() {
        // printStr("Hello");  // ❌ 错误：不能隐式转换
        MyString t1;
        printStr(MyString("Hello"));  // ✅ 必须显式构造
        return 0;
    }