#include "PathLength.h"
#include "Poly.h"
#include "Function.h"
#include "CenterDifference.h"
using CSC2110::Poly;

#include <iostream>
using namespace std;

int main()
{
   double* coeffs1 = new double[4];
   coeffs1[0] = 20;
   coeffs1[1] = 0;
   coeffs1[2] = -1;
      coeffs1[3] = 0;

   double* coeffs2 = new double[4];
   coeffs2[0] = 9;
   coeffs2[1] = 4;
   coeffs2[2] = 1;
         coeffs2[3] = 0;

   double* coeffs3 = new double[4];
   coeffs3[0] = 5;
   coeffs3[1] = -1;
   coeffs3[2] = 0;
         coeffs3[3] = 0;

   Poly* poly1 = new Poly(3);  //coefficients, max power (a copy of coeffs made)
   Poly* poly2 = new Poly(3);
   Poly* poly3 = new Poly(3);
   for (int i = 0; i <= 3; i++)
   {
	   poly1->setCoeff(i, coeffs1[i]);
	   poly2->setCoeff(i, coeffs2[i]);
	   poly3->setCoeff(i, coeffs3[i]);
   }

   delete[] coeffs1;
   delete[] coeffs2;
   delete[] coeffs3;
  

   Function** polys = new Function*[3];
   polys[0] = poly1;
   polys[1] = poly2;
   polys[2] = poly3;

   Path* pl = new Path(polys, 0);  //specify the starting parameter value (ul)
   

	
   PathLength* findu = new PathLength(pl);

   double* xyz = pl->getPosition(pl->getLower());
   cout << "ul: " << pl->getLower() << endl;
   cout << "x: " << xyz[0] << endl;
   cout << "y: " << xyz[1] << endl;
   cout << "z: " << xyz[2] << endl;
   cout << endl;

   for (int i = 1; i <= 5; i++)
   {
      double* temp = findu->advance(7.2);  //move forward by a path length of 7.2
      delete[] xyz;
      xyz = temp;
      cout << "ul: " << pl->getLower() << endl;
      cout << "x: " << xyz[0] << endl;
      cout << "y: " << xyz[1] << endl;
      cout << "z: " << xyz[2] << endl;
      cout << endl;
   }
   

   delete[] xyz;
   delete findu;

   return 0;
} 	

