#if !defined (MODIFIEDSECANT_H)
#define MODIFIEDSECANT_H

#include "Function.h"
using CSC2110::Function;

class ModifiedSecant
{
   private:

   public:
      static double* modifiedSecant(Function* f, double x1, double x2, int max);
      static double* modifiedSecant(Function* f, double x1, double x2, double tol, int max);

};

#endif
