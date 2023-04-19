#include <bits/stdc++.h>
using namespace std;

class ComplexNumbers
{
private:
float real;
float imaginary;
public:
ComplexNumbers()
{
real=5;
imaginary=5;
}
ComplexNumbers(int real,int imaginary)
{
this->real=real;
this->imaginary=imaginary;
}
void print()
{ cout<<"result of arithmetic operation:"<<endl;
cout<<real<<" + "<<"i"<<imaginary<<endl;
}
void plus(ComplexNumbers const &c2)
{
real=real+c2.real;
imaginary=imaginary+c2.imaginary;
}
void subtract(ComplexNumbers const &c2)
{
real=real-c2.real;
imaginary=imaginary-c2.imaginary;
}
};
int main()
{
float real1, imaginary1, real2, imaginary2;
ComplexNumbers c3;
cout<<"to show default constructor"<<endl;
c3.print();
cout<<"Enter c1"<<endl;

cin >> real1 >> imaginary1;
cout<<"Enter c2"<<endl;
cin >> real2 >> imaginary2;
ComplexNumbers c1(real1, imaginary1);
ComplexNumbers c2(real2, imaginary2);
while(1)
{
cout<<"1:"<<"add"<<endl;
cout<<"2:"<<"subtract"<<endl;
cout<<"3:"<<"exit"<<endl;
int choice;
cin >> choice;
if(choice == 1) {
c1.plus(c2);
c1.print();
}
else if(choice == 2) {
c1.subtract(c2);
c1.print();
}
else if(choice==3) {
break;
}
else{
cout<<"invalid choice"<<endl;
}
}
}
