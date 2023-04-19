#include <bits/stdc++.h>
using namespace std;
class Employee
{
private:
string cName;
bool boolEmployed;
public:
Employee(string name);
string getName() const
{
return cName;
}
bool isEmployed() const
{
return boolEmployed;
}
void setEmployed(bool employed)
{
boolEmployed = employed;
}
};
vector<Employee*> vecEmp;
Employee::Employee(string name)
{
cName = name;
boolEmployed = true;
// pushing all employees
vecEmp.push_back(this);
cout << "Employee created with name: " << cName << endl;
}
class Company
{
private:
string cName;
vector<Employee *> cEmp;
public:
Company(string name) : cName(name)
{
cout << "Company established with name: " << cName << endl;
}
~Company()
{
for (auto e : cEmp)
{
e->setEmployed(false);
}
}
void getEmployees()
{
cout << "Employees of " << cName << ":" << endl;
for (auto e : cEmp)
{
cout << e->getName() << endl;
}
}
void addEmployee(Employee *employee)
{
cEmp.push_back(employee);
cout << "Employee associated with the company: " <<cName<<" and
Employee: "<< employee->getName() << endl;
}
string getName() const
{
return cName;
}
vector<Employee *> getEmployees() const
{
return cEmp;
}
};
int main()
{
Employee e1("Employee A");
Employee e2("Employee B");
Employee e3("Employee C");
Company c1("Google");
Company c2("Apple");
c1.addEmployee(&e1);
c1.addEmployee(&e2);
c2.addEmployee(&e3);
c1.getEmployees();
cout << "\nDeleting the company..." << endl;
c1.~Company();
cout << "\nUnemployed employees:" << endl;
for(auto x: vecEmp)
{
if(x->isEmployed()==false)
{
cout<<x->getName()<<endl;
}
}
return 0;
}
