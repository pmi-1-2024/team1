#include "Books.h"
#include "Library.h"
Books::Books() : ID_book(0), book_name(" "), year(0), page_count(0), library_id(0) {}
Books::Books(int IDb, string bn, int ye, list<Author> aut, Publisher pub, int pc, list<Genre> gen)
    : ID_book(IDb), book_name(bn), year(ye), authors(aut), publisher(pub), page_count(pc), genres(gen), library_id(0) {}
Books::~Books() {}

int Books::getID_book() const { return ID_book; }
string Books::getBook_name() const { return book_name; }
int Books::getYear() const { return year; }
int Books::getPages() const { return page_count; }
list<Author> Books::getAuthors() const { return authors; }
Publisher Books::getPublisher() const { return publisher; }
list<Genre> Books::getGenres() const { return genres; }
int Books::getLibraryID() const { return library_id; }
void Books::setLibraryID(int id) { library_id = id; }

void Books::print(ostream& os) const {
    os << "ID: " << ID_book << ", Name: " << book_name << ", Year: " << year << " ";
	os << "Authors: ";
	for (const auto& author : authors) {
		os << author.author_name << " " << author.surname << ", ";
	}
	os << endl;
	os << "Publisher: " << publisher.publish_name << ", Address: " << publisher.address << endl;
    os << "Page Count: " << page_count << endl;
	os << "Genres: ";
	for (const auto& genre : genres) {
		os << genre.genre_name << ", ";
	}
	os << endl;
    os << "Located in Library ID: " << library_id << endl;
}
void Books::read(istream& is) {
    authors.clear();
    genres.clear();

	cout << "ID: ";
    is >> ID_book;
    cout << "Book name: ";
    is >> book_name;
    cout << "Year: ";
    is >> year;

	cout << "Number of authors: ";
    int num_authors;
    is >> num_authors;
    for (int i = 0; i < num_authors; ++i) {
        Author author;
        author.read(is);
        authors.push_back(author);
    }

	cout << "Publisher: ";
    publisher.read(is);
	cout << "Page count: ";
    is >> page_count;

	cout << "Number of genres: ";
    int num_genres;
    is >> num_genres;
    for (int i = 0; i < num_genres; ++i) {
        Genre genre;
		genre.read(is);
        genres.push_back(genre);
    }

    cout << "Library ID: ";
    is >> library_id;
}

ostream& operator<<(ostream& os, const Books& b) {
    os << b.ID_book << " " << b.book_name << " " << b.year << endl;
	os << b.authors.size() << " ";
	for (const auto& author : b.authors) {
		os << author.ID_autor << " " << author.author_name << " " << author.surname << " ";
	}
    os <<endl << b.publisher.ID_publish << " " << b.publisher.publish_name << " " << b.publisher.address << " "
        << b.page_count;
	os << "\n" << b.genres.size() << " ";
	for (const auto& genre : b.genres) {
		os << genre.ID_genre << " " << genre.genre_name << " ";
	}
    os << b.library_id << " ";


	os << endl;
	return os;
}
istream& operator>>(istream& is, Books& b) {
     b.authors.clear();
     b.genres.clear();
     is >> b.ID_book >> b.book_name >> b.year;

     int num_authors;
     is >> num_authors;
     for (int i = 0; i < num_authors; ++i) {
         Author author;
         is >> author;
         b.authors.push_back(author);
     }

     is >> b.publisher;
     is >> b.page_count;

     int num_genres;
     is >> num_genres;
     for (int i = 0; i < num_genres; ++i) {
         Genre genre;
         is >> genre;
         b.genres.push_back(genre);
     }
     is >> b.library_id;

    return is;
}
