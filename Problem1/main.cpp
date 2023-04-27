#include <iostream>
#include <crtdbg.h>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
void exercise1() {
	// TODO your code here
	Circle c1{ 10, 10, 1 };
    std::cout << c1.toString()<< std::endl;
	Shape* c2{ new Circle{0, 0, 100 } };
    std::cout << c2->toString()<< std::endl;
	Circle c3{ -10, 0, 2 };
    std::cout << c3.toString()<< std::endl;


	Shape *s1{ new Square{ 0, 0, 2 }};
    std::cout << s1->toString()<< std::endl;
	Square s2{ 10, 20, 17 };
    std::cout << s2.toString()<< std::endl;
	Square s3{ 9, 100, 0.3 };
    std::cout << s3.toString()<< std::endl;
	
	// 1. create a polymorphic static array shapes with 6 elements that holds c1, c2, c3 and s1, s2 and s3

	Shape* polymorphic_array[] = {&c1, c2, &c3, s1, &s2, &s3};
	
	// 2. display all the elements that have an area greater than 10

	std::cout << "------------------------------------------------" << std::endl;

	for (int i = 0; i < 6; i++) {
		if (polymorphic_array[i]->area() > 10) {
			std::cout << polymorphic_array[i]->toString() << std::endl;
		}
	}
	// 3. display all the circles from the array shapes

	std::cout << "------------------------------------------------" << std::endl;

	for (int i = 0; i < 6; i++) {
		Circle* cp{ dynamic_cast<Circle*>(polymorphic_array[i]) };
		if (cp != nullptr) {
			std::cout << cp->toString() << " Circle" << std::endl;
		}
		else if (cp==nullptr) {
			std::cout << polymorphic_array[i]->toString() << " Not Circle" << std::endl;
		}
	}
		
	
	delete s1;
	delete c2;
	delete[] polymorphic_array;

}
int main() {

	exercise1();
	_CrtDumpMemoryLeaks();
	return 0;
}

