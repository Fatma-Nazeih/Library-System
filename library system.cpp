#include <iostream>
#include <vector>
#include <string>
using namespace std;

static int num;

int menu() {
    int choice;
    cout << "Welcome To Library System" << endl;
    cout << "1. Add a Book" << endl;
    cout << "2. Number of Books" << endl;
    cout << "3. Borrow a Book" << endl;
    cout << "4. Return a Book" << endl;
    cout << "5. Display Books" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    cin.ignore();
    return choice;
}

class EBook {
protected:
    vector<string> title;
    vector<string> des;
    vector<int> price;
    vector<string> author;
    vector<string> editor;

public:
    bool operator==(const string& s) {
        for (const auto& it : title) {
            if (it == s) {
                return true;
            }
        }
        return false;
    }
};

class Printed {
protected:
    vector<string> titlep;
    vector<string> desp;
    vector<int> pricep;
    vector<string> authorp;
    vector<string> editorp;
    int copy;

public:
    bool operator==(const string& s) {
        for (const auto& it : titlep) {
            if (it == s) {
                return true;
            }
        }
        return false;
    }
};

class Library : public EBook, public Printed {
public:
    void add(const string& s, int i, const string& d, const string& a, const string& e, int p) {
        if (Printed::operator==(s) || EBook::operator==(s)) {
            cout << "Book already exists." << endl;
            return;
        }

        if (i == 1) {
            titlep.push_back(s);
            desp.push_back(d);
            authorp.push_back(a);
            editorp.push_back(e);
            pricep.push_back(p);
            copy++;
            num++;
        }
        else if (i == 0) {
            title.push_back(s);
            des.push_back(d);
            author.push_back(a);
            editor.push_back(e);
            price.push_back(p);
            num++;
        }

        cout << "Book Added Successfully." << endl;  
    }


    void borrow(const string& s, int i) {
        if (Printed::operator==(s) || EBook::operator==(s)) {
            if (i == 1) {
                cout << "The book is available; you can pick it up from here." << endl;
            }
            else if (i == 0) {
                cout << "The book is available; you can download it from here." << endl;
            }
        }
        else {
            cout << "Unfortunately, this book is unavailable." << endl;
        }
    }

    void RETURN(const string& s) {
        for (size_t j = 0; j < titlep.size(); ++j) {
            if (titlep[j] == s) {
                copy++;
                cout << "Printed book returned successfully." << endl;
                return;
            }
        }
        cout << "This book was not borrowed from our library." << endl;
    }

    void display(const string& s, int i) {
        if (i == 1 && Printed::operator==(s)) {
            for (size_t j = 0; j < titlep.size(); ++j) {
                if (titlep[j] == s) {
                    cout << "Title: " << titlep[j] << endl;
                    cout << "Description: " << desp[j] << endl;
                    cout << "Author: " << authorp[j] << endl;
                    cout << "Editor: " << editorp[j] << endl;
                    cout << "Price: " << pricep[j] << endl;
                    cout << "Available Copies: " << copy << endl;
                    return;
                }
            }
        }
        else if (i == 0 && EBook::operator==(s)) {
            for (size_t j = 0; j < title.size(); ++j) {
                if (title[j] == s) {
                    cout << "Title: " << title[j] << endl;
                    cout << "Description: " << des[j] << endl;
                    cout << "Author: " << author[j] << endl;
                    cout << "Editor: " << editor[j] << endl;
                    cout << "Price: " << price[j] << endl;
                    return;
                }
            }
        }
        cout << "This book is unavailable." << endl;
    }
};

int main() {
    Library book;
    while (true) {
        int choice = menu();

        if (choice == 1) {
            string tt, dd, aa, ee;
            int ss, pp;

            cout << "Enter Book's Title: ";
            cin.ignore();
            getline(cin, tt);
            cout << "Enter Book's Author: ";
            getline(cin, aa);
            cout << "Enter Book's Editors: ";
            getline(cin, ee);
            cout << "Enter Book's Description: ";
            getline(cin, dd);

            while (true) {
                cout << "Enter Book's Price: ";
                cin >> pp;
                if (pp < 0) {
                    cout << "Invalid Value, Please Enter a Positive Value." << endl;
                }
                else {
                    break;
                }
            }

            cout << "EBook(0) Or Printed(1): ";
            cin >> ss;

            book.add(tt, ss, dd, aa, ee, pp);
        }
        else if (choice == 2) {
            cout << "Currently we are offering " << num << " books." << endl;
        }
        else if (choice == 3) {
            string name;
            int n;
            cout << "Enter Title of the book: ";
            cin.ignore();
            getline(cin, name);
            cout << "EBook(0) Or Printed(1): ";
            cin >> n;
            book.borrow(name, n);
        }
        else if (choice == 4) {
            string s;
            cout << "Enter Title of the book: ";
            cin.ignore();
            getline(cin, s);
            book.RETURN(s);
        }
        else if (choice == 5) {
            string s;
            int n;
            cout << "Enter Title of the book to display: ";
            cin.ignore();
            getline(cin, s);
            cout << "EBook(0) Or Printed(1): ";
            cin >> n;
            book.display(s, n);
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid Input" << endl;
        }
    }

    return 0;
}
