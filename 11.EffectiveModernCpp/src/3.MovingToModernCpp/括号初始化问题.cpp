#include <iostream>
#include <vector>
using namespace std;

class Widget
{
private:
    /* data */
public:
    Widget(int i, bool b);
    Widget(int i, double d);
    Widget(std::initializer_list<long double> il); 
    ~Widget();
};

Widget::Widget(int i, bool b)
{
    cout << "Widget(int i, bool b)" << endl;
}

Widget::Widget(int i, double d)
{
    cout << "Widget(int i, double d)" << endl;
}

Widget::Widget(std::initializer_list<long double> il)
{
    cout << "Widget(std::vector<long double> il)" << endl;
}

Widget::~Widget()
{
}



int main(int argc, char const *argv[])
{
    Widget w1(1, true);
    Widget w2(2, 3.14);
    Widget w3{2, 3.14};
    return 0;
}
