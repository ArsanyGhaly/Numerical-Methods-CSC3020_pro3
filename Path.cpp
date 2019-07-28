#include "Path.h"
#include <cmath> 
#include "Function.h"
#include "CenterDifference.h"
#include <iostream> 

using namespace std; 
using CSC2110::Function;

Path::Path(Function** p, double val)
{
	polys = p; 
	ul = val; 
}

 double Path::evaluate(double x)
 {
	 CenterDifference* center_diff = new CenterDifference(); 
	 double sum_partial_squares ;
	 double partial_1 = center_diff->differentiate(polys[0],.0001,x);
	 double partial_2 = center_diff->differentiate(polys[1],.0001,x);
	 double partial_3 = center_diff->differentiate(polys[2],.0001,x);

	 sum_partial_squares = pow(partial_1,2) + pow(partial_2,2) + pow(partial_3,2);
	double path = sqrt(sum_partial_squares);
	
	return path; 
 }
 double Path::getLower()
 {
	 
	 return ul; 
	 
 }
 void Path::setLower(double lower)
 {
	 ul = lower; 
 }
double* Path::getPosition(double start_val)
{
		double* coordinates = new double[3]; 
		
		for(int i =0; i < 3; i++)
		{
			coordinates[i] = polys[i]->evaluate(start_val); 
		}
		
		return coordinates; 
}	