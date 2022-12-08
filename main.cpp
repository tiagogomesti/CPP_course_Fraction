#include "Fraction.h"

int main(void)
{
	Fraction f1(1,2), f2(2,3), f;
	cout << f1 << "->" << f1.to_double() << endl;
	cout << f2 << "->" << f2.to_double() << endl;
	f = f1 + f2;
	cout << f1 << "+" << f2 << "=" << f << endl;
	f = f2 + f2 + f2;
	cout << f2 << "+" << f2 << "+" << f2 << "=" << f << endl;	
	f = !f;
	cout << f2 << "+" << f2 << "+" << f2 << "=" << f << endl;
	f = f1 * f2;
	cout << f1 << "*" << f2 << "=" << f << endl;
	f = f1 / f2;
	cout << f1 << ":" << f2 << "=" << f << endl;
	Fraction f3(7,8);
	f3 += f1;
	cout << f3 << endl;
	return 0;
}