#include "ModifiedSecant.h"
#include <cmath>

double* ModifiedSecant::modifiedSecant(Function* f, double l, double u, int max)
{
   return modifiedSecant(f, l, u, -1, max);
}

double* ModifiedSecant::modifiedSecant(Function* f, double x, double d, double tol, int max)
{
   if (max < 0)
   {
      max = 10;
   }

   double displacement = d; //static displacement

   double fx = f->evaluate(x);
   double fd = f->evaluate(x + displacement);

   double r = x - (displacement * fx) / (fd - fx);
   double fr = f->evaluate(r);  

   int iter = 1;
   double error = tol + 1;    //skip the error calc the first time through

   while (error > tol && iter < max)  //need to have a max number of iterations in case there are no zeroes between l and u
   {
      x = r;
      fx = fr;

      fd = f->evaluate(r + displacement);
      
      r = x - (displacement * fx) / (fd - fx);
      fr = f->evaluate(r);

      if (fr == 0)
      {
         error = 0;
         break;
      }

      if (fabs(r) > .0001)  //avoid divide by zero
      {
         error = fabs((r - x) / r);  //approximate error
      }
      else
      {
         error = 1;
      }

      iter++;
   }    

   double* temp = new double[3];
   temp[0] = r;
   temp[1] = error;
   temp[2] = iter;

   return temp;    
}