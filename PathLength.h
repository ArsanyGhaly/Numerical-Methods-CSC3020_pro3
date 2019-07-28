#if !defined (PATHLENGTH_H)
#define PATHLENGTH_H

#include "Function.h"
#include "Romberg.h"
#include "CenterDifference.h"
#include "Path.h"

using CSC2110::Function;

class PathLength : public Function
{
   private:
		Path* path; 
		double d;
   public:
	double* advance(double distance); 
	PathLength(Path* p)
	{
		path = p;
	}
	double evaluate(double x);


};

#endif