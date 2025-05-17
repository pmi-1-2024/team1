#include "Books.h"
Books::Books() : ID_book(0), book_name(" "), year(0), page_count(0) {}
Books::Books(int IDb, string bn, int ye, list<Author> aut, Publisher pub, int pc, list<Genre> gen)
	: ID_book(IDb), book_name(bn), year(ye), authors(aut), publisher(pub), page_count(pc), genres(gen) {}

int Books::getID_book() const { return ID_book; }
string Books::getBook_name() const { return book_name; }
int Books::getYear() const { return year; }
int Books::getPages() const { return page_count; }
list<Author> Books::getAuthors() const { return authors; }
Publisher Books::getPublisher() const { return publisher; }
list<Genre> Books::getGenres() const { return genres; }

void Books::setID_book(int IDb) { ID_book = IDb; }
void Books::setBook_name(string bn) { book_name = bn; }
void Books::setYear(int ye) { year = ye; }
void Books::setPages(int pc) { page_count = pc; }
void Books::setAuthors(list<Author> aut) { authors = aut; }
void Books::setPublisher(Publisher pub) { publisher = pub; }
void Books::setGenres(list<Genre> gen) { genres = gen; }

void Books::print(ostream& os) const {
    os << "ID: " << ID_book << ", Name: " << book_name << ", Year: " << year;
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
}
void Books::read(istream& is) {
    authors.clear();
    genres.clear();

    is >> ID_book >> book_name >> year;

    int num_authors;
    is >> num_authors;
    for (int i = 0; i < num_authors; ++i) {
        Author author;
        is >> author.ID_autor >> author.author_name >> author.surname;
        authors.push_back(author);
    }

    is >> publisher.ID_publish >> publisher.publish_name >> publisher.address;
    is >> page_count;

    int num_genres;
    is >> num_genres;
    for (int i = 0; i < num_genres; ++i) {
        Genre genre;
        string raw_genre;
        is >> genre.ID_genre >> raw_genre;

        // Видаляємо кому в кінці, якщо є
        if (!raw_genre.empty() && raw_genre.back() == ',') {
            raw_genre.pop_back();
        }

        genre.genre_name = raw_genre;
        genres.push_back(genre);
    }
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
	os << endl;
	return os;
}
istream& operator>>(istream& is, Books& b) {
	b.read(is);
	return is;
}