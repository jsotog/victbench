#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

double euler(double);
int main()
{
   clock_t start; 
   start=clock(); 
   double h = 5;
   euler(h);
   std::cout << (clock()-start)/(double)CLOCKS_PER_SEC << std::endl;
   return 0;
}


double euler(double h)
{
   double ynp1=0,ynp1prima=0,yn=1,ynprima=1;
   for(double x=0; x<=1.5;x+=h)
     {
	ynp1prima=ynprima+h;
	ynp1=yn+h*ynprima;
	ynprima=ynp1prima;
	yn=ynp1;	
     }
   return ynp1;
}
