#include <iostream>
#include <string>
#include <vector>

enum class Booktype {tech, art};

class Books {
private:

	const std::string m_title;
	const std::string m_author;
	const Booktype m_type;

public:

	Books(const std::string& title, const std::string& author, const Booktype type) : m_title(title), m_author(author), m_type(type) {}
	
	~Books(){}

	const std::string get_title() const { return m_title; }
	const std::string get_author() const { return m_author; }
	const Booktype get_type() const { return m_type; }
};

class Library {
private:

	std::vector <Books> m_books;

public:
	
	void add_book(const std::string& title, const std::string& author, const Booktype type) {
		if (title.empty() == 0 && author.empty() == 0)
			m_books.push_back(Books(title, author, type));
		else
			std::cout << author << " " << title << " - has no author or title!" << std::endl;
	}
	
	void print_books() {
	for (const Books& obj : m_books) {
		std::cout << obj.get_title() << " " << obj.get_author() << " ";
		switch (obj.get_type()) {

		case Booktype::tech:
			std::cout << "- tech book" << std::endl;
			break;
		case Booktype::art:
			std::cout << "- art book" << std::endl;
			break;
		default:
			std::cout << "- unknown" << std::endl;

		}
	}
}
	void count_type_switch() {
		unsigned count_tech = 0;
		unsigned count_art = 0;
		for (const Books& obj : m_books) {
			switch (obj.get_type()) {
			case Booktype::tech:
				count_tech++;
				break;
			case Booktype::art:
				count_art++;
				break;
			}
		}
		std::cout << "Art books: " << count_art << std::endl;
		std::cout << "Tech books: " << count_tech << std::endl;
	}

	void count_type_if() {
		unsigned count_tech = 0;
		unsigned count_art = 0;
		for (const Books& obj : m_books) {
			if (obj.get_type() == Booktype::art)
				count_art++;
			else if (obj.get_type() == Booktype::tech)
				count_tech++;
		}
		std::cout << "Art books: " << count_art << std::endl;
		std::cout << "Tech books: " << count_tech << std::endl;
	}
};

int main() {
	Library book_collection;

	book_collection.add_book("The Divine Comedy", "Dante", Booktype::art);
	book_collection.add_book("", "-.-", Booktype::tech);
	book_collection.add_book(":/", "", Booktype::art);
	book_collection.add_book("Great Expectations", "Charles Dickens", Booktype::art); 
	book_collection.add_book("A Tour of C++", "Bjarne Stroustrup", Booktype::tech); 
	book_collection.add_book("The Hitchhiker’s Guide to the Galaxy", "Douglas Adams", Booktype::art); 
	book_collection.add_book("The best explanations with comments", "ZOMGL", Booktype::tech);

	book_collection.print_books();

	std::cout << std::endl;

	book_collection.count_type_switch();

	std::cout << std::endl;

	book_collection.count_type_if();

}