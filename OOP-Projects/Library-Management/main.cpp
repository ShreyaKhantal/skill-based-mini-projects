#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int newbookid = 1;//global variable

class Book {
    int bookid;
    string title;
    string author;
    bool avail;
public:
    Book(int a, string b, string c) : bookid(a), title(b), author(c), avail(true) {}

    int getbookid() { return bookid; }
    string gettitle() { return title; }
    string getauthor() { return author; }
    bool isavail() { return avail; }

    void issuebook() {
        if (avail) {
            avail = false;
            cout << "Book issued" << endl;
        } else {
            cout << "Book Unavailable" << endl;
        }
    }
    void returnbook() {
        if (!avail) {
            avail = true;
            cout << "Book Returned" << endl;
        } else {
            cout << "Book Issued" << endl;
        }
    }
    void display() {
        cout << "Book ID: " << bookid << "\nTitle: " << title << "\nAuthor: " << author << "\nAvailable: " << (avail ? "Yes" : "No") << endl;
    }
};

class Member {//Abstrct class as two pure virtual functions
public:
    string name;
    int memid;
    vector<int> borrowid;

    Member(string a, int b) : name(a), memid(b) {}

    string getname() { return name; }
    int getmemid() { return memid; }

    virtual void display() = 0;
    virtual bool canborrow() = 0;

    void borrowbook(int bookid) {
        borrowid.push_back(bookid);
    }
    void returnbook(int bookid) {
        for (auto i = borrowid.begin(); i != borrowid.end(); i++) {
            if (*i == bookid) {
                borrowid.erase(i);
                break;
            }
        }
    }
    bool didborrow(int bookid) {
        for (auto i = borrowid.begin(); i != borrowid.end(); i++) {
            if (*i == bookid) {
                return true;
            }
        }
        return false;
    }
};

class Student : public Member {
public:
    Student(string a, int b) : Member(a, b) {}

    void display() override {
        cout<<"Student Name: " << name <<" Student ID: "<<memid<< endl;
    }
    bool canborrow() override {
        return borrowid.size() < 5;
    }
};
class Faculty : public Member {
public:
    Faculty(string a, int b) : Member(a, b) {}

    void display() override {
        cout<<"Faculty Name: "<< name<< " Faculty ID: "<<memid<< endl;
    }
    bool canborrow() override {
        return true;
    }

};

class Library {
    vector<Book> books;
    vector<Member*> members;
public:
    void addbook(string n, string a, int copies) {
        for (int i = 0; i < copies; i++) {
            Book newbook(newbookid++, n, a);
            books.push_back(newbook);
        }
        cout << "Book Added\n";
    }
    void addstudent(string n, int id) {
        members.push_back(new Student(n, id));
        cout << "Student Added\n";
    }
    void addfaculty(string n, int id) {
        members.push_back(new Faculty(n, id));
        cout << "Faculty Added\n";
    }
    Member* findmember(int id) {
        for (auto i = members.begin(); i != members.end(); i++) {
            if ((*i)->getmemid() == id) {
                return *i;
            }
        }
        return NULL;
    }
    bool isavail(int id) {
        for (auto i = books.begin(); i != books.end(); i++) {
            if ((i)->getbookid() == id) {
                return (i)->isavail();
            }
        }
        return false;
    }
    void issue(int bookid, int memid) {
        for (auto i = books.begin(); i != books.end(); i++) {
            if (i->getbookid() == bookid) {
                Member* member = findmember(memid);
                if (member) {
                    if (member->canborrow()) {
                        if (i->isavail()) {
                            i->issuebook();
                            member->borrowbook(bookid);
                        } else {
                            cout << "Book is already issued\n";
                        }
                    } else {
                        cout << "5 books already issued\n";
                    }
                } else {
                    cout << "Borrower not found\n";
                }
                return;
            }
        }
        cout << "Book not found\n";
    }
    void returnbook(int bookid, int memid) {
        for (auto i = books.begin(); i != books.end(); i++) {
            if (i->getbookid() == bookid) {
                Member* member = findmember(memid);
                if (member) {
                    if (member->didborrow(bookid)) {
                        i->returnbook();
                        member->returnbook(bookid);
                    } else {
                        cout << "This book was not borrowed\n";
                    }
                } else {
                    cout << "Borrower not found\n";
                }
                return;
            }
        }
        cout << "Book not found\n";
    }
    void displaybooks() {
        for (auto i = books.begin(); i != books.end(); i++) {
            i->display();
            cout << "--------------------\n";
        }
    }
    void displaymembers() {
        for (auto i = members.begin(); i != members.end(); i++) {
            (*i)->display();
            cout << "--------------------\n";
        }
    }
};

int main() {
    Library library;
    int choice;
    int bookID, borrowerID;
    cout<<"----Library Management System----" << endl;
    cout<<"1. Display all Books" << endl;
    cout<<"2. Display all Members"<<endl;
    cout<<"3. Borrow Book" << endl;
    cout<<"4. Return Book" << endl;
    cout<<"5. Add Book" << endl;
    cout<<"6. Add Member" << endl;
    cout<<"7. Exit" << endl;

    do {
        cout << endl << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Display all books
                library.displaybooks();
                break;
            case 2:
                library.displaymembers();
                break;
            case 3: {// Borrow book
                
                cout << "Enter Book ID: ";
                cin >> bookID;
                cout << "Enter Borrower ID: ";
                cin >> borrowerID;
                library.issue(bookID, borrowerID);
                break;
            }
            case 4: // Return book
                cout << "Enter Book ID: ";
                cin >> bookID;
                cout << "Enter Borrower ID: ";
                cin >> borrowerID;
                library.returnbook(bookID, borrowerID);
                break;
            case 5: {// Add book
                int copies;
                string title, author;
                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Number of Copies: ";
                cin >> copies;
                library.addbook(title, author, copies);
                break;
            }
            case 6: {// Add member
                int id, memberType;
                string name;
                cout << "Enter Member Type (1-Student/2-Faculty): ";
                cin >> memberType;
                cin.ignore(); // Ignore newline character
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter ID: ";
                cin >> id;
                if (memberType == 1) {
                    library.addstudent(name, id);
                } else if (memberType == 2) {
                    library.addfaculty(name, id);
                } else {
                    cout << "Invalid member type.\n";
                }
                break;
            }
            case 7:
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 7);
    return 0;
}
