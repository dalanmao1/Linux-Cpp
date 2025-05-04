#include <iostream>
using namespace std;

class A
{
public:
    virtual void vfunc1()
    {
        cout << "A:vfunc1()" << endl;
    }
    virtual void vfunc2()
    {
        cout << "A:vfunc2()" << endl;
    }
    void func1()
    {
        cout << "A:func1()" << endl;
    }
    void func2()
    {
        cout << "A:func2()" << endl;
    }
    virtual ~A()
    {
        cout << "A::dtor" << endl;
    }

private:
    int m_data1, m_data2;
};

class B : public A
{
public:
    virtual void vfunc1()
    {
        cout << "B:vfunc1()" << endl;
    }
    void func2()
    {
        cout << "B:func2()" << endl;
    }
    virtual ~B()
    {
        cout << "B::dtor" << endl;
    }
private:
    int m_data3;
};

class C : public B
{

public:
    virtual void vfunc1()
    {
        cout << "C:vfunc1()" << endl;
    }
    void func2()
    {
        cout << "C:func2()" << endl;
    }
     ~C()
    {
        cout << "C::dtor" << endl;
    }
private:
    int m_data1, m_data4;
};

int main()
{
    A* pa = new A();
    A* pb = new B();
    A* pc = new C();
    std::cout << "Hello World!\n";
    delete pa;
    delete pb;
    delete pc;
}