#include "Rational.h"
#include <iostream>
#include "Rational.cpp"

int main() {
Rational a(2, 4), b(3, 6), c, d, e, f;

c = a + b;
std::cout << "a + b = " << c.toRationalString() << std::endl;

d = a - b;
std::cout << "a - b = " << d.toRationalString() << std::endl;

e = a * b;
std::cout << "a * b = " << e.toRationalString() << std::endl;

f = a / b;
std::cout << "a / b = " << f.toRationalString() << std::endl;

return 0;
}
