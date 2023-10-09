#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book
{
public:
    string title;
    string author;
    int isbn;
    bool available;

    Book(string title, string author, int isbn) : title(title), author(author), isbn(isbn), available(true) {}
};

class Library
{
private:
    vector<Book> books;
    int finePerDay;

public:
    Library() : finePerDay(100) {}

    void addBook(const string title, const string author, int isbn)
    {
        books.emplace_back(title, author, isbn);
        cout << "Book added: " << title << endl;
    }

    void displayBooks()
    {
        cout << "Library Books:" << endl;
        for (int i = 0; i < books.size(); ++i)
        {
            const Book book = books[i];
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "ISBN: " << book.isbn << endl;
            cout << "Status: " << (book.available ? "Available" : "Not Available") << endl;
            cout << "------------------------" << endl;
        }
    }

    Book *findBook(int isbn)
    {
        for (int i = 0; i < books.size(); ++i)
        {
            if (books[i].isbn == isbn)
            {
                return &books[i];
            }
        }
        return nullptr;
    }

    void checkoutBook(int isbn)
    {
        Book *book = findBook(isbn);

        if (book && book->available)
        {
            book->available = false;
            cout << "Book checked out: " << book->title << endl;
        }
        else
        {
            cout << "Book not available or not found." << endl;
        }
    }

    void returnBook(int isbn, int daysLate)
    {
        Book *book = findBook(isbn);

        if (book && !book->available)
        {
            book->available = true;
            int fine = daysLate * finePerDay;

            if (fine > 0)
            {
                cout << "Book returned late. Fine: Rs. " << fine << endl;
            }
            else
            {
                cout << "Book returned on time." << endl;
            }
        }
        else
        {
            cout << "Book not checked out or not found." << endl;
        }
    }
};

int main()
{
    Library library;

    while (true)
    {
        cout << "Library Management System" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Check Out Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title, author;
            int isbn;
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            cin >> isbn;
            library.addBook(title, author, isbn);
            break;
        }
        case 2:
            library.displayBooks();
            break;
        case 3:
        {
            int isbn;
            cout << "Enter ISBN to check out: ";
            cin >> isbn;
            library.checkoutBook(isbn);
            break;
        }
        case 4:
        {
            int isbn, daysLate;
            cout << "Enter ISBN to return: ";
            cin >> isbn;
            cout << "Enter days late: ";
            cin >> daysLate;
            library.returnBook(isbn, daysLate);
            break;
        }
        case 5:
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}