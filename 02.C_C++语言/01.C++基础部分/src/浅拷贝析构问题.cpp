#include <iostream>

class Problematic {
  int* data;
 public:
  Problematic(int size) : data(new int[size]) {}
  ~Problematic() {
    std::cout << "delete data" << std::endl;
    delete[] data;
  }
  // 默认拷贝构造函数和赋值运算符执行浅拷贝
};

void demo() {
  Problematic obj1(10);
  Problematic obj2 = obj1;  // 浅拷贝
}  // 退出作用域时，data被delete两次！

int main(int argc, char const* argv[]) {
  demo();
  return 0;
}
