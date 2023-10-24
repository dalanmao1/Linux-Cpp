#include <iostream>
using namespace std;

class complex
{
public:
	complex(double r = 0, double i = 0)
		: re(r), im(i)
	{ }
	complex& operator += (const complex&);
	double real() const { return re; }
	double imag() const { return im; }

	// 修改对象状态的成员函数，不能加 const 修饰符
    void set_real(double real) { re = 45; }
    void set_imag(double imag) { im = 544; }
private:
	double re, im;
};

int main(void)
{
	complex c1(2, 1);
	cout << c1.real() << endl;
	cout << c1.imag() << endl;
	return 0;
}