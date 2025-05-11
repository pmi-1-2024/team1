#ifndef LIBRARYBOOKS_H
#define LIBRARYBOOKS_H

class LibraryBooks {
private:
    int library_id;
    int book_id;
    int amount;

public:
    LibraryBooks() : library_id(0), book_id(0), amount(0) {}
    LibraryBooks(int libId, int bookId, int amt)
        : library_id(libId), book_id(bookId), amount(amt) {}

    int getLibraryId() const { return library_id; }
    int getBookId() const { return book_id; }
    int getAmount() const { return amount; }

    void setLibraryId(int id) { library_id = id; }
    void setBookId(int id) { book_id = id; }
    void setAmount(int amt) { amount = amt; }
};

#endif
