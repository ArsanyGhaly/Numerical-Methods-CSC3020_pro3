#include "Romberg.h"
#include <cmath>
#include "CenterDifference.h"
#include <iostream> 
using namespace std; 
double Romberg::accurateRomberg(Function* f, double a, double b, int level, int numVars)
{
int num_points; 
double* trap_integration = new double[level+1];
double ba = b-a;
QueueLinked<double>** queues = new QueueLinked<double>*[2]; 
QueueLinked<double>* active_queue = new QueueLinked<double>();
QueueLinked<double>* other_queue = new QueueLinked<double>();

for(int c =0; c <= level; c++)
{
	num_points = pow(2,c);
	double h = ba/num_points;
	double x1 = a; 
	double trap =0; 
	
	for(int i=0; i < num_points; i++)
	{
		
		double x2 = x1 +h; 
		double h2 = h/2; 
		double sum = (f->evaluate(x1) + f->evaluate(x2));
		trap += h2 *sum;
		x1 += h; 
	}

	trap_integration[c] =trap;
	active_queue->enqueue(&trap);
}


double Im,Il; 
int count = 1;
double next_level_val;
double rom_val; 

int k =0;
int r = 1; 
while(!active_queue->isEmpty() || !other_queue->isEmpty())
{
	
	double w = pow(4,count);
	if(count % 2 == 1)
	{
	Il= *(active_queue->dequeue()); 
	Im= *(active_queue->peek()); 
	next_level_val = (((w*Im)-Il) /(w -1));
	other_queue->enqueue(&next_level_val);
	
	if(active_queue->size() == 1)
	{
		rom_val = *(active_queue->dequeue()); 
		count++; 
	}
	if(active_queue->isEmpty() && other_queue->size() == 1)
	{
		rom_val = *(other_queue->dequeue()); 
	}
	}
	else
	{
	Il= *(other_queue->dequeue()); 
	Im= *(other_queue->peek()); 
	next_level_val = (((w*Im)-Il) /(w -1));
	active_queue->enqueue(&next_level_val);
	
	if(other_queue->size() == 1)
	{
		rom_val = *(other_queue->dequeue()); 
		count++; 
	}
	if(other_queue->isEmpty() && active_queue->size() == 1)
	{
		rom_val = *(active_queue->dequeue()); 
	}
	}
	
	
}

return rom_val;
}