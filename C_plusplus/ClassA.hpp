#ifndef CLASSA_H
#define CLASSA_H
#pragma once
#include <iostream>	
class ClassA  
{
	private:
		//In C++17 you can use inline variables, which you can use even outside classes
		//https://stackoverflow.com/questions/18860895/how-to-initialize-static-members-in-the-header
		inline static int objCount=0;
	public:
		//What assumptions have you made?
		//using "static" keyword for member functions and variables
		//the above belong to "class" itself rather than object.
		ClassA();
		~ClassA();
		static int nobjs();

};
#endif