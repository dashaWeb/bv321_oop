#pragma once
#include <iostream>

namespace shape {
	const double SIDE = 10;
	const double PI = 3.14;
	double areaSquare(double side);


	namespace rect {
		double area(double width, double height);
	}
}


namespace mka {
	class Student {
		std::string name;
		int age;
	public:
		Student(const std::string& name, const int& age)
			:name{name},age{age}{}
		void print() const {
			std::cout << "------ Student MKA -------" << std::endl;
			std::cout << "\t Name :: " << name << std::endl;
			std::cout << "\t Age  :: " << age << std::endl;
		}
	};
}

namespace st_3 {
	class Student {
		std::string name;
		int age;
	public:
		Student(const std::string& name, const int& age)
			:name{ name }, age{ age } {}
		void print() const {
			std::cout << "------ Student ST-3 -------" << std::endl;
			std::cout << "\t Name :: " << name << std::endl;
			std::cout << "\t Age  :: " << age << std::endl;
		}
	};
}