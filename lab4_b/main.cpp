#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>
#include <fstream>




class literature {
public:
	int number;
	std::string title;

};

struct sort_literature {

	bool operator () (const literature& lit_item1, const literature& lit_item2) {
		int ascii1 = (unsigned char)lit_item1.title[0];
		int ascii2 = (unsigned char)lit_item2.title[0];
		
		if ((ascii1 >= 192 && ascii1 <= 255) && !(ascii2 >= 192 && ascii2 <= 255)) { return true; }
		if (!(ascii1 >= 192 && ascii1 <= 255) && (ascii2 >= 192 && ascii2 <= 255)) { return false; }
		
		return lit_item1.title < lit_item2.title;
	}

};

void print_sort_literature_with_number(std::vector <literature>& BD) {
	std::sort(BD.begin(), BD.end(), sort_literature());
	for (const literature& obj : BD) {
		std::cout << obj.number << ". " << obj.title << std::endl;
	}
}

void print_sort_literature_without_number(std::vector <literature>& BD) {
	std::sort(BD.begin(), BD.end(), sort_literature());
	for (const literature& obj : BD) {
		std::cout << obj.title << std::endl;
	}
}

void load_text(const std::string& file_name, std::vector<literature>& BD) {
	std::ifstream file(file_name);
	if (!file.is_open())
		std::cout << "file dont open(" << std::endl;
	else {
		std::string line;
		int liter_number = 1;
		while (std::getline(file, line)) {
			literature item;
			item.number = liter_number;
			item.title = line.substr(3 + (liter_number/10));
			liter_number++;
			BD.push_back(item);
		}
		file.close();
	}
}



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<literature> books;

	load_text("file.txt", books);
	print_sort_literature_with_number(books);
	std::cout << "________________________________________________________________________" << std::endl;
	print_sort_literature_without_number(books);
	
	return 0;
}