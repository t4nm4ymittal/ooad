#include <iostream>
using namespace std;
class Complex {
public:
Complex(double realPart=0.0, double imaginaryPart=0.0)
: realPart(realPart), imaginaryPart(imaginaryPart) {}
double realPart;
double imaginaryPart;
// Overloading << operator for output
friend std::ostream &operator<<(std::ostream &out, const Complex &c) {
out << c.realPart << " + " << c.imaginaryPart << "i";
return out;
}
// Overloading >> operator for input
friend std::istream &operator>>(std::istream &in, Complex &c) {
in >> c.realPart >> c.imaginaryPart;
return in;
}
// Overloading * operator for multiplication
Complex operator*(const Complex &c) const {
return Complex(realPart * c.realPart - imaginaryPart * c.imaginaryPart,
realPart * c.imaginaryPart + imaginaryPart * c.realPart);
}
// Overloading == operator for equality comparison
bool operator==(const Complex &c) const {
return realPart == c.realPart && imaginaryPart == c.imaginaryPart;
}
// Overloading != operator for inequality comparison
bool operator!=(const Complex &c) const {
return !(*this == c);
}
};
int main()
{
Complex c1,c2;
cout<<"Enter 1st complex number"<<endl;

cin>>c1;
cout<<"Enter 2nd complex number"<<endl;
cin>>c2;
cout<<"Your numbers are"<<endl;
cout<<"c1:"<<c1<<endl<<"c2:"<<c2<<endl;
Complex result;
// Multiplication
result = c1 * c2;
cout << "The result of multiplication is: " << result<<endl;;
// Equality comparison
if (c1 == c2) {
cout << "The two complex numbers are equal." << endl;
}
else {
cout << "The two complex numbers are not equal." << endl;
}
// Inequality comparison
if (c1 != c2) {
cout << "The two complex numbers are not equal." << endl;
}
else {
cout << "The two complex numbers are equal." << endl;
}
return 0;
}
