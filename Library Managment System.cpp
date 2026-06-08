#include <iostream>
#include <string>
using namespace std;
class Book {
public:
    int id;
    string title;
    string author;
    bool issued;
    void addBook(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        issued = false;
    }

    void displayBook() {
        cout << "\nBook ID : " << id;
        cout << "\nTitle   : " << title;
        cout << "\nAuthor  : " << author;
        cout << "\nStatus  : " << (issued ? "Issued" : "Available") << endl;
    }
};
class Library {
private:
    Book books[100];
    int count;
public:
    Library() {
        count = 0;
    }
    void addBook() {
        if (count >= 100) {
            cout << "Library is full!\n";
            return;
        }
        int id;
        string title, author;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
        books[count].addBook(id, title, author);
        count++;
        cout << "Book added successfully!\n";
    }
    void displayBooks() {
        if (count == 0) {
            cout << "No books available.\n";
            return;
        }
        cout << "\n===== Library Books =====\n";
        for (int i = 0; i < count; i++) {
            books[i].displayBook();
            cout << "----------------------\n";
        }
    }
    void searchBook() {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                cout << "\nBook Found:\n";
                books[i].displayBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }
    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                if (!books[i].issued) {
                    books[i].issued = true;
                    cout << "Book issued successfully.\n";
                } else {
                    cout << "Book already issued.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }
    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                if (books[i].issued) {
                    books[i].issued = false;
                    cout << "Book returned successfully.\n";
                } else {
                    cout << "Book was not issued.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }
    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                for (int j = i; j < count - 1; j++) {
                    books[j] = books[j + 1];
                }
                count--;
                cout << "Book deleted successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};
int main() {
    Library lib;
    int choice;
    do {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.displayBooks();
                break;
            case 3:
                lib.searchBook();
                break;
            case 4:
                lib.issueBook();
                break;
            case 5:
                lib.returnBook();
                break;
            case 6:
                lib.deleteBook();
                break;
            case 7:
                cout << "Thank you!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 7);
    return 0;
}