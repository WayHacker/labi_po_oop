#include <iostream>
#include <string>
#include <vector>
#include <fstream>


class Cars {
private:
	
	std::string m_model;

public:

	Cars(const std::string& model) : m_model(model) {}
	virtual ~Cars() {}
	virtual void print_model () = 0;

	const std::string& get_model() const { return m_model; }

};



class Toyota : public Cars {
public:

	Toyota(const std::string& model) : Cars(model){}
	virtual ~Toyota() { print_model(); }
	void print_model(){std::cout << "Toyota" << get_model() << std::endl; }
};

class Ford : public Cars {
public:

	Ford (const std::string& model) : Cars(model){}
	virtual ~Ford() { print_model(); }
	void print_model() { std::cout << "Ford" << get_model() << std::endl; }
};

class Lamborghini : public Cars {
public:

	Lamborghini(const std::string& model) : Cars(model){}
	virtual ~Lamborghini() { print_model(); }
	void print_model() { std::cout << "Lamborghini" << get_model() << std::endl; }
};



int main(){
	std::vector <std::shared_ptr <Cars> > list_car;
	std::fstream file;
	file.open("list_of_cars_laba.txt");

	if (file.is_open()) {
		std::string name, model;
		while (file >> name >> model) {
			if (name == "Toyota") list_car.push_back(std::make_shared<Toyota>(model));
			else if (name == "Ford") list_car.push_back(std::make_shared<Ford>(model));
			else if (name == "Lamborghini") list_car.push_back(std::make_shared<Lamborghini>(model));
		}

	}
	else std::cout << "The file is not open!";
	file.close();

	return 0;
}

