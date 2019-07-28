#if !defined (CENTERDIFFERENCE_H)
#define CENTERDIFFERENCE_H
#include<iostream> 
#include "Function.h"
using CSC2110::Function;
using namespace std; 

class CenterDifference
{
   private:

   public:
   
   CenterDifference()
   {
	   
   }
   
	double differentiate(Function* f, double h, double value)
	{
	double diff;
	double x1 = value +h; 
	double x2 = value -h;
	
	diff = ((f->evaluate(x1) - f->evaluate(x2)) / (h *2));
	return diff; 

	}
   


};

#endif