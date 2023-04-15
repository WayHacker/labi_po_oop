#include <iostream>
#include <typeinfo>
#include <vector>



class Class_1 {
public:

	virtual void output() {
		std::cout << "Here class 1." << std::endl;
	}
};

class Class_2 : public Class_1 {
public:

	void output() override {
		std::cout << "Here class 2." << std::endl;
	}
};



void my_copy(Class_1* obj, std::vector<Class_1*> db) {
	Class_1* copy = 0;
	if (dynamic_cast<Class_2*>(obj)) {
		copy = new Class_2(*dynamic_cast<Class_2*>(obj));
	}
	else {
		copy = new Class_1(*dynamic_cast<Class_1*>(obj));
	}
	db.push_back(copy);
}


int main() {
	Class_1 obj_1;
	Class_2 obj_2;

	std::vector<Class_1*> database;
	
	my_copy(&obj_1, database);
	my_copy(&obj_2, database);

	for (std::vector<Class_1*>::iterator iter = database.begin(); iter != database.end(); iter++) {
		std::cout << typeid(**iter).name << std::endl;
		delete* iter;
	}
	return 0;
}