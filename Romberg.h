#if !defined (ROMBERG_H)
#define ROMBERG_H

#include "Function.h"
#include "QueueLinked.h"


using CSC2110::Function;
using CSC2110::QueueLinked;
class Romberg
{
   private:

   public:
   Romberg()
   {
	   
   }
    double accurateRomberg(Function* f, double a, double b, int level, int numVars);


};

#endif
