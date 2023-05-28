#include <vector>
#include <iostream>

class Detail {
protected:
	Detail() { std::cout << "This is class Detail" << std::endl; }
public:
	template <typename T> 
	friend void add_vector(std::vector<Detail*>& v);

};

class Assembling : public Detail {
protected:
	Assembling() { std::cout << "This is Assembling" << std::endl; }
public:
	template <typename T> 
	friend void add_vector(std::vector<Detail*>& v);
};

template <typename T> void add_vector(std::vector <Detail*>& v)
{
	v.push_back(new T);
}

int main() {
	std::vector <Detail*> v1;
	add_vector<Assembling>(v1);
	add_vector<Detail>(v1);
	return 0;

}