#include <iostream>
using namespace std;
class Employee {
private:
    int empId;
    string name;
    float basicSalary;
    float allowances;
    float deductions;
public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> empId;

        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;

        cout << "Enter Allowances: ";
        cin >> allowances;

        cout << "Enter Deductions: ";
        cin >> deductions;
    }
    float calculateSalary() {
        return basicSalary + allowances - deductions;
    }
    void display() {
        cout << "\n----- Employee Payslip -----\n";
        cout << "Employee ID   : " << empId << endl;
        cout << "Employee Name : " << name << endl;
        cout << "Basic Salary  : " << basicSalary << endl;
        cout << "Allowances    : " << allowances << endl;
        cout << "Deductions    : " << deductions << endl;
        cout << "Net Salary    : " << calculateSalary() << endl;
    }
};
int main() {
    Employee emp;
    cout << "=== Employee Payroll System ===\n";
    emp.getData();
    emp.display();
    return 0;
}