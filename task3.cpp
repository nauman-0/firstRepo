#include <iostream>
#include <string>

using namespace std;

template <typename T, typename V>
T* linearSearchTemplate(T array[], int size, V target) {
    for (int i = 0; i < size; i++) {
        if (array[i].getSearchKey() == target) {
            return &array[i];
        }
    }
    return nullptr;
}

template <typename T, typename V>
T* binarySearchTemplate(T array[], int size, V target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid].getSearchKey() == target) {
            return &array[mid];
        }
        if (array[mid].getSearchKey() < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return nullptr;
}

class LibraryItem {
public:
    virtual void display() = 0;
};

class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;

public:
    Book() {
        title = "";
        author = "";
        pages = 0;
    }

    Book(string bookTitle, string bookAuthor, int bookPages) {
        title = bookTitle;
        author = bookAuthor;
        pages = bookPages;
    }

    string getTitle() {
        return title;
    }

    string getSearchKey() {
        return title;
    }

    int getPages() {
        return pages;
    }

    void display() {
        cout << "Book: " << title << ", Author: " << author << ", Pages: " << pages << endl;
    }
};

class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper() {
        name = "";
        date = "";
        edition = "";
    }

    Newspaper(string paperName, string paperDate, string paperEdition) {
        name = paperName;
        date = paperDate;
        edition = paperEdition;
    }

    string getName() {
        return name;
    }

    string getSearchKey() {
        return name;
    }

    string getEdition() {
        return edition;
    }

    void display() {
        cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << endl;
    }
};

class Library {
private:
    Book books[20];
    Newspaper newspapers[20];
    int bookCount;
    int newspaperCount;

public:
    Library() {
        bookCount = 0;
        newspaperCount = 0;
    }

    void addBook(Book b) {
        books[bookCount] = b;
        bookCount++;
    }

    void addNewspaper(Newspaper n) {
        newspapers[newspaperCount] = n;
        newspaperCount++;
    }

    void displayCollection() {
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (books[j].getPages() > books[j + 1].getPages()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = 0; j < newspaperCount - i - 1; j++) {
                if (newspapers[j].getEdition() > newspapers[j + 1].getEdition()) {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(string title) {
        return linearSearchTemplate<Book, string>(books, bookCount, title);
    }

    Newspaper* searchNewspaperByName(string name) {
        return linearSearchTemplate<Newspaper, string>(newspapers, newspaperCount, name);
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    } else {
        cout << "\nBook not found.\n";
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    } else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}