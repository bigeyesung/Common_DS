#include "ClassA.hpp"

ClassA::ClassA()
{
	//increase when obj is created
    objCount++;
}
	
ClassA::~ClassA()
{
	//increase when obj is destroyed
    objCount--;
}

int ClassA::nobjs()
{
    return objCount;
}