/*
 * MyClass.h
 *
 *  Created on: Oct 17, 2021
 *      Author: WilliamWoker
 */

#ifndef MYCLASS_H_
#define MYCLASS_H_

#include <iostream>

//to create a template class, I applied a solution with the placement of all the code in the header file

template<typename n> //template type parameter n
class MyClass
{
	public:

		MyClass() //default constructor
		{
			// TODO Auto-generated constructor stub
			std::cout << "main constructor" << std::endl;
		}
		MyClass(const MyClass &other) //copy constructor
		{
			x = other.x;
			std::cout << "copy constructor" << std::endl;
		}
		MyClass(MyClass &&other) //move constructor
				: x(other.x)
		{
			std::cout << "move constructor" << std::endl;
		}
		MyClass& operator=(const MyClass &other) //copy assignment operator
		{
			if (&other == this)
				return *this;

			x = other.x;

			std::cout << "copy assignment operator" << std::endl;

			return *this;
		}
		MyClass& operator=(MyClass &&other) //move assignment operator
		{
			if (&other == this)
				return *this;

			x = other.x;

			std::cout << "move assignment operator" << std::endl;

			return *this;
		}
		virtual ~MyClass()
		{
			// TODO Auto-generated destructor stub
			std::cout << "destructor" << std::endl;
		}

		n& get_x() //public reference-getter for 'x' member
		{
			std::cout << "getter" << std::endl;
			return x;
		}
	private:
		n x; //private data member 'x' of type n
};

#endif /* MYCLASS_H_ */
