#include <iostream>

class ResourceHolder {
public:
    ResourceHolder() {
        std::cout << "Constructor: Allocating resource." << std::endl;
        // 模拟分配资源
        resource = new int[100];
    }

    ~ResourceHolder() {
        std::cout << "Destructor: Releasing resource." << std::endl;
        // 释放资源
        delete[] resource;
    }

private:
    int* resource;
};

int main() {
    ResourceHolder* obj = new ResourceHolder[10];
    // 使用 free 释放内存，而不是 delete
    free(obj); 
    // delete[] obj;
    return 0;
}