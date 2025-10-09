#include <iostream>
using namespace std;

class Book {
private:
    string bookId, bookName, bookAuthor, bookISBN;
    double bookPrice;

public:
    Book() {}
    Book(string id, string name, double price, string author, string isbn)
        : bookId(id), bookName(name), bookPrice(price), bookAuthor(author), bookISBN(isbn) {}

    // Getters
    string getBookId() { return bookId; }
    string getBookName() { return bookName; }
    double getBookPrice() { return bookPrice; }
    string getBookAuthor() { return bookAuthor; }
    string getBookISBN() { return bookISBN; }

    // Setters
    void setBook(string id, string name, double price, string author, string isbn) {
        bookId = id; bookName = name; bookPrice = price; bookAuthor = author; bookISBN = isbn;
    }

    void printBook() {
        cout << "BookID: " << bookId << ", Name: " << bookName
             << ", Price: " << bookPrice << ", Author: " << bookAuthor
             << ", ISBN: " << bookISBN << endl;
    }
};

class Node {
public:
    Book book;
    Node* next;

    Node(Book b) { book = b; next = nullptr; }
};

class BookList {
private:
    Node* last;

public:
    BookList() { last = nullptr; }

    void addBook(string id, string name, double price, string author, string isbn) {
        Book b(id, name, price, author, isbn);
        Node* newNode = new Node(b);
        if (!last) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        cout << "Book added successfully!\n";
    }

    void removeBook(string id) {
        if (!last) { cout << "List is empty!\n"; return; }

        Node* curr = last->next;
        Node* prev = last;
        do {
            if (curr->book.getBookId() == id) {
                if (curr == last && curr->next == last) last = nullptr;
                else {
                    prev->next = curr->next;
                    if (curr == last) last = prev;
                }
                delete curr;
                cout << "Book deleted successfully!\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);

        cout << "Book not found!\n";
    }

    void updateBook(string id, string name, double price, string author, string isbn) {
        if (!last) { cout << "List is empty!\n"; return; }

        Node* temp = last->next;
        do {
            if (temp->book.getBookId() == id) {
                temp->book.setBook(id, name, price, author, isbn);
                cout << "Book updated successfully!\n";
                return;
            }
            temp = temp->next;
        } while (temp != last->next);

        cout << "Book not found!\n";
    }

    void printBooks() {
        if (!last) { cout << "No books found!\n"; return; }

        Node* temp = last->next;
        cout << "\nBook List:\n";
        do {
            temp->book.printBook();
            temp = temp->next;
        } while (temp != last->next);
    }

    void printBook(string id) {
        if (!last) { cout << "No books found!\n"; return; }

        Node* temp = last->next;
        do {
            if (temp->book.getBookId() == id) {
                cout << "Book Found:\n";
                temp->book.printBook();
                return;
            }
            temp = temp->next;
        } while (temp != last->next);

        cout << "Book not found!\n";
    }
};

int main() {
    BookList bl;

    // Add 10 books
    for (int i = 1; i <= 10; i++)
        bl.addBook("B" + to_string(i), "Book" + to_string(i), 100 + i, "Author" + to_string(i), "ISBN" + to_string(i));

    bl.printBooks();

    // Print one book
    bl.printBook("B5");

    // Remove valid and invalid
    bl.removeBook("B2");
    bl.removeBook("B50");

    // Print again
    bl.printBooks();

    // Update a book
    bl.updateBook("B3", "UpdatedBook", 199.9, "UpdatedAuthor", "UpdatedISBN");
    bl.printBook("B3");

    return 0;
}


