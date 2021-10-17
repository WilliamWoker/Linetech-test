//============================================================================
// Name        : Task4.cpp
// Author      : WilliamWoker
// Version     :
// Copyright   : 
// Description : Realization of template class. Copy and move constructors
//				 will be different if we use dynamic memory allocation.
//============================================================================

#include <iostream>
#include "MyClass.h"

int main()
{
	MyClass<int> mc1;
	mc1.get_x() = 18;

	std::cout << mc1.get_x() << std::endl;

	MyClass<int> mc2;
	mc2 = mc1;
	std::cout << mc1.get_x() << std::endl;
	std::cout << mc2.get_x() << std::endl;

	return 0;
}
