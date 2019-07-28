#include "PathLength.h"
#include <cmath> 
#include "Romberg.h"
#include "ModifiedSecant.h"
#include "Function.h"
#include <iostream> 
using namespace std; 
using CSC2110::Function;

double* PathLength::advance(double distance)
{
	
	d = distance; 
	ModifiedSecant* secant = new ModifiedSecant(); 
	double* uh = secant->modifiedSecant(this,path->getLower(),d, .0001, 100); 
	path->setLower(uh[0]); 
	return path->getPosition(path->getLower()); 
	
	
}
double PathLength::evaluate(double x)
{
	
	Romberg* rom = new Romberg(); 
	double uh = x;
	double ul = path->getLower(); 
	double integration = rom->accurateRomberg(path,ul,uh,5,1);
	double value = integration - d;
	
	
	return value;
}