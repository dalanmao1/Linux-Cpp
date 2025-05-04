#include <algorithm>  // for std::copy
#include <iostream>
#include <cstring>
class String {
  char* m_data;
  size_t m_length;

 public:
  // 构造函数
  String(const char* str = "") {
    m_length = strlen(str);
    m_data = new char[m_length + 1];  // +1 for null terminator
    std::copy(str, str + m_length + 1, m_data);
  }

  // 1. 拷贝构造函数 (深拷贝)
  String(const String& other)
      : m_length(other.m_length), m_data(new char[other.m_length + 1]) {
    std::copy(other.m_data, other.m_data + m_length + 1, m_data);
    std::cout << "deep copy\n";
  }

  // 2. 拷贝赋值运算符 (深拷贝)
  String& operator=(const String& other) {
    // 检查自赋值
    if (this != &other) {
      // 先释放原有资源
      delete[] m_data;

      // 分配新资源并复制内容
      m_length = other.m_length;
      m_data = new char[m_length + 1];
      std::copy(other.m_data, other.m_data + m_length + 1, m_data);
    }
    std::cout << "depp copy operator\n";
    return *this;
  }

  // 3. 析构函数
  ~String() {
    delete[] m_data;
    std::cout << "deep copy ~\n";
  }

  // 辅助函数：打印字符串
  void print() const { std::cout << m_data << "\n"; }

  // 交换函数 (用于拷贝交换惯用法)
  friend void swap(String& first, String& second) noexcept {
    using std::swap;
    swap(first.m_length, second.m_length);
    swap(first.m_data, second.m_data);
  }
};

int main() {
  // 测试拷贝构造函数
  String str1("Hello");
  String str2 = str1;  // 调用拷贝构造函数

  std::cout << "str1: ";
  str1.print();
  std::cout << "str2: ";
  str2.print();

  //修改str2不影响str1
  String str3("World");
  str2 = str3;  // 调用拷贝赋值运算符

  std::cout << "after str1: ";
  str1.print();
  std::cout << "after str2: ";
  str2.print();

  return 0;
}