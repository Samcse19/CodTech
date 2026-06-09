#include <iostream>
#include <string>
using namespace std;
struct Contact {
    string name;
    string phone;
};
int main() {
    Contact contacts[100];
    int count = 0;
    int choice;
    do {
        cout << "\n===== Contact Management System =====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, contacts[count].name);

                cout << "Enter Phone Number: ";
                getline(cin, contacts[count].phone);

                count++;
                cout << "Contact Added Successfully!\n";
                break;
            case 2:
                if(count == 0) {
                    cout << "No Contacts Available!\n";
                } else {
                    cout << "\nContact List:\n";
                    for(int i = 0; i < count; i++) {
                        cout << i + 1 << ". "
                             << contacts[i].name
                             << " - "
                             << contacts[i].phone << endl;
                    }
                }
                break;
            case 3: {
                string searchName;
                bool found = false;
                cout << "Enter Name to Search: ";
                cin.ignore();
                getline(cin, searchName);
                for(int i = 0; i < count; i++) {
                    if(contacts[i].name == searchName) {
                        cout << "Contact Found!\n";
                        cout << "Name: " << contacts[i].name << endl;
                        cout << "Phone: " << contacts[i].phone << endl;
                        found = true;
                        break;
                    }
                }
                if(!found)
                    cout << "Contact Not Found!\n";

                break;
            }
            case 4: {
                string deleteName;
                bool found = false;
                cout << "Enter Name to Delete: ";
                cin.ignore();
                getline(cin, deleteName);
                for(int i = 0; i < count; i++) {
                    if(contacts[i].name == deleteName) {
                        for(int j = i; j < count - 1; j++) {
                            contacts[j] = contacts[j + 1];
                        }
                        count--;
                        found = true;
                        cout << "Contact Deleted Successfully!\n";
                        break;
                    }
                }
                if(!found)
                    cout << "Contact Not Found!\n";

                break;
            }
            case 5:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while(choice != 5);
    return 0;
}