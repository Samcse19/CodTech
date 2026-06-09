#include <iostream>
using namespace std;
int main() {
    int customerID;
    char customerName[50];
    int units;
    float billAmount;
    cout << "===== Electricity Bill Generator =====" << endl;
    cout << "Enter Customer ID: ";
    cin >> customerID;
    cout << "Enter Customer Name: ";
    cin.ignore();
    cin.getline(customerName, 50);
    cout << "Enter Units Consumed: ";
    cin >> units;
    if (units <= 100)
        billAmount = units * 1.5;
    else if (units <= 300)
        billAmount = (100 * 1.5) + ((units - 100) * 2.5);
    else if (units <= 500)
        billAmount = (100 * 1.5) + (200 * 2.5) + ((units - 300) * 4.0);
    else
        billAmount = (100 * 1.5) + (200 * 2.5) + (200 * 4.0) + ((units - 500) * 6.0);
    cout << "\n===== Electricity Bill =====" << endl;
    cout << "Customer ID   : " << customerID << endl;
    cout << "Customer Name : " << customerName << endl;
    cout << "Units Used    : " << units << endl;
    cout << "Bill Amount   : Rs. " << billAmount << endl;
    return 0;
}