#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <algorithm>

class Worked {
public:

	Worked(const std::string& name, int date_of_birth, const std::string& role, int group)
		: name_(name), date_of_birth_(date_of_birth), role_(role), group_(group) {}
	~Worked (){}

	const std::string& get_name() const { return name_; }
	const int get_date() const { return date_of_birth_; }
	const std::string& get_role() const { return role_; }
	const int get_group() const { return group_; }
	


private:
	std::string name_;
	int date_of_birth_;
	std::string role_;
	int group_;

};



void load_text (const std::string& file_name, std::vector<Worked>& BD){
	std::ifstream file(file_name);
	if (!file.is_open())
		std::cout << "file dont open(" << std::endl;
	else {
		std::string line;
		while (std::getline(file, line)) {
			line.erase(std::remove(line.begin(), line.end(), ','), line.end());
			std::string name, role, inicials, group;
			int birth,number_group;
			std::stringstream ss(line);

			ss >> name >> inicials >> birth >> role >> group >> number_group;
			std::string full_name = name + " " + inicials;
			
			BD.push_back({ full_name, birth, role, number_group });

		}
		file.close();
	}
}

void print_engineers(const std::vector<Worked>& BD) {
	std::cout << "Инженеры:" << std::endl;
	for (const Worked& human : BD) {
		if (human.get_role() == "инженер")
			std::cout << "ФИО: " << human.get_name() << " Год рожения: " << human.get_date() << ", Группа " << human.get_group() << std::endl;

	}

}

void print_not_chairmen(std::vector<Worked>& BD) {
	/*
	std::vector <Worked> not_chairmen;
	
	std::copy_if(BD.begin(), BD.end(), back_inserter(not_chairmen), [](const Worked& obj) { return obj.get_role() != "председатель"; });

	std::sort(not_chairmen.begin(), not_chairmen.end(), [](const Worked& emp1, const Worked& emp2) {
	return emp1.get_date() < emp2.get_date();});

	std::cout << "Люди не являющиеся председателями: " << std::endl;
	for (const Worked& human : not_chairmen)	
	std::cout << "ФИО: " << human.get_name() << " Год рождения: " << human.get_date() << ", Должность: " << human.get_role() << ", Группа: " << human.get_group() << std::endl;

	*/

	std::cout << "Люди не являющиеся председателями: " << std::endl;
	std::sort(BD.begin(), BD.end(), [](const Worked& emp1, const Worked& emp2) {
		return emp1.get_date() < emp2.get_date(); });
	for (const Worked& human : BD) {
		if (human.get_role() != "председатель") {
			std:: cout << "ФИО: " << human.get_name() << " Год рождения: " << human.get_date() << ", Должность: " << human.get_role() << ", Группа: " << human.get_group() << std::endl;
		}
	}
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<Worked> BD;
	load_text("file.txt", BD);
	print_engineers(BD);
	std::cout << std::endl;
	print_not_chairmen(BD);
	

	return 0;
}
