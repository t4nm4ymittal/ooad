if 0
#include <iostream>  // cout/endl

// Our polynomial class.
#include "polynomial.h"

using std::cout;
using std::endl;

int main()
{
	Polynomial<double> a;

	a.setTerm(2, 2.);
	a.setTerm(1, -2.);
	a.setTerm(0, 2.);

	Polynomial<double> b({ { 2, 3. },{ 1, 3. },{ 0, 3. } });

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "add: " << a + b << endl;
	cout << " multiply: " << a * b << endl;

	return 0;
}
#endif
