#if !defined (PATH_H)
#define PATH_H

#include "Function.h"
#include "Romberg.h"
#include "CenterDifference.h"
#include "CenterDifference.h"
using CSC2110::Function;


class Path : public Function
{
   private:
		
	double ul;
    Function** polys;
   public:
    Path()
	{
		
	}
	Path(Function** p, double val);
    double getLower(); 
	double* getPosition(double start_val); 
	double evaluate(double x);
	void setLower(double lower);
};

#endif
