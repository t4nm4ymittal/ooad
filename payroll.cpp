#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Employee {
protected:
    string name;
    double rate;
    int hours;

public:
    Employee() : name(""), rate(0.0), hours(0) {}
    Employee(string n, double r, int h) : name(n), rate(r), hours(h) {}
    
    string getname(){
        return this->name;
    }
    
    
    virtual double getRegularPay() const = 0;
    virtual double getOvertimePay() const = 0;
    virtual double getGrossPay() const = 0;
    virtual double getTaxAmount() const = 0;
    virtual double getNetPay() const = 0;
};

class HourlyEmployee : public Employee {
public:
    HourlyEmployee() : Employee() {}
    HourlyEmployee(string n, double r, int h) : Employee(n, r, h) {}
    
    string getname() const{
        return name;
    }
    double getRegularPay() const {
        if (hours <= 40) {
            return rate * hours;
        }
        else {
            return rate * 40;
        }
    }

    double getOvertimePay() const {
        if (hours <= 40) {
            return 0.0;
        }
        else {
            return (hours - 40) * rate * 1.5;
        }
    }

    double getGrossPay() const {
        return getRegularPay() + getOvertimePay();
    }

    double getTaxAmount() const {
        return getGrossPay() * 0.2;
    }

    double getNetPay() const {
        return getGrossPay() - getTaxAmount();
    }
};

class SalaryEmployee : public Employee {
private:
    double salary;
    int overtimeHours;

public:
    SalaryEmployee() : Employee(), salary(0.0), overtimeHours(0) {}
    SalaryEmployee(string n, double s, int oh) : Employee(n, 0.0, 0), salary(s), overtimeHours(oh) {}

    double getRegularPay() const {
        return salary / 52.0;
    }

    double getOvertimePay() const {
        double hourlyRate = salary / 52.0 / 40.0;
        return overtimeHours * hourlyRate * 1.5;
    }

    double getGrossPay() const {
        return getRegularPay() + getOvertimePay();
    }

    double getTaxAmount() const {
        return getGrossPay() * 0.2;
    }

    double getNetPay() const {
        return getGrossPay() - getTaxAmount();
    }
};

bool cmp(Employee* e1, Employee* e2){
    return e1->getNetPay() < e2->getNetPay();
}

int main() {
    vector<Employee*> employees;

    employees.push_back(new HourlyEmployee("kapil", 15.0, 45));
    employees.push_back(new HourlyEmployee("rajat", 20.0, 30));
    employees.push_back(new SalaryEmployee("prabal", 50000.0, 10));

    double minNetPay = employees[0]->getNetPay();
    double maxNetPay = employees[0]->getNetPay();
    for (int i = 0; i < employees.size(); i++) {
        double netPay = employees[i]->getNetPay();
        if (netPay < minNetPay) {
            minNetPay = netPay;
        }
        if (netPay > maxNetPay) {
            maxNetPay = netPay;
        }
    }

    sort(employees.begin(), employees.end(),cmp);
    cout<<"Name    NetPay"<<endl;
    for(int i=0;i<employees.size();i++){
        cout<<employees[i]->getname()<<"    "<<employees[i]->getNetPay()<<endl;
    }
}
